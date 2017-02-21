#include "Quiz.hpp"

Quiz::Quiz(uint64_t q_num, std::string path)
{
  srand(time(NULL)); // dummy pseudo-random seed

  _question_count = 0;
  if(q_num > 0)
  {
    _questions = new Question[q_num];
    _question_size = q_num;
  }
  else
  {
    fprintf(stderr, "Invalid amount of questions!\n");
    _questions = nullptr;
    return;
  }

  if(!question_loadfromfile(path))
  {
    fprintf(stderr, "Error during loading questions!\n");
    return;
  }
}

Quiz::~Quiz()
{
  if(_questions != nullptr)
    delete[] _questions;
}

bool Quiz::question_loadfromfile(std::string path)
{
  std::ifstream file(path);
  if(!file.is_open())
  {
    fprintf(stderr, "Cannot open file: %s!\n", path.c_str());
    return false;
  }

  int i = 0;
  while(!file.eof() && i < _question_size)
  {
    /* NOTICE: no parsing err-check */
    std::getline(file, _questions[i].question);

    for(int j=0; j < Q_NUM; ++j)
    {
      std::getline(file, _questions[i].answer[j], '\n');
    }
    
    std::string correct;
    std::getline(file, correct);
    _questions[i].correct = std::stoi(correct);

    ++_question_count;
    ++i;
  }
  file.close();

  return true;
}

void Quiz::question_print(int idx)
{
  fprintf(stdout, "%s\n", _questions[idx].question.c_str());
  for(int i = 0; i < Q_NUM; ++i)
  {
    fprintf(stdout, "[%d] %s\n", i, _questions[idx].answer[i].c_str());
  }
}

int Quiz::Play(int q_count)
{
  if(q_count < 1 || q_count > _question_count)
  {
    fprintf(stderr, "Invalid amount of questions to ask! (to ask: %d, available: %lu\n",
            q_count, _question_count);
    return 1;
  }
  
  fprintf(stdout, "Quiz 2017 (by shead)\n---------------\n\n");
  int score = 0;
  for(int i = 0; i < q_count; ++i)
  {
    fprintf(stdout, "--Question %d--\n", i);
    int qidx = rand() % q_count; // not uniq
    question_print(qidx);

    int ans;
    fprintf(stdout, "Enter answer (0-%d): ", Q_NUM-1);
    scanf("%d", &ans);

    if(ans == _questions[qidx].correct)
    {
      fprintf(stdout, "Yay! +1 point!\n");
      ++score;
    }
    else
      fprintf(stdout, "Nope :(\n");
    
    puts("");
  }
  fprintf(stdout, "\n!GAME OVER!\nYour Score: %d (max: %d)\n", score, q_count);
  return 0;
}
