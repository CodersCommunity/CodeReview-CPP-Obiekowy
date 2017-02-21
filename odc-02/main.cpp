#include "Quiz.hpp"

int main()
{
  Quiz quiz(5, "questions.txt");
  return quiz.Play(3);
}
