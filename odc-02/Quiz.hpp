#pragma once

#include <string>
#include <cstdio>
#include <cstdint>
#include <fstream>
#include <ctime>

#define Q_NUM 4

class Quiz {
public:
  Quiz(uint64_t questions_count, std::string questions_path);
  ~Quiz();

  int Play(int q_to_ask); // main loop

private:
  struct Question {
    std::string question;
    std::string answer[Q_NUM];
    int correct;
  };

  Question* _questions; // all questions
  uint64_t _question_count; // amount of q's
  uint64_t _question_size; // arr size

  void question_print(int index); // print
  bool question_loadfromfile(std::string path);
};
