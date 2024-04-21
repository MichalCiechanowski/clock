#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

std::vector<std::string> addStringVector(std::vector<std::string> str1, std::vector<std::string> str2);
std::vector<std::string> getNumber(int number);
void displayTime();

int main() {
  for (;;) {
    displayTime();
    std::this_thread::sleep_for(std::chrono::milliseconds(950));
    system("clear");
  }
  return 0;
}

std::vector<std::string> addStringVector(std::vector<std::string> str1, std::vector<std::string> str2) {
  std::vector<std::string> answer;

  for (int i = 0; i < str1.size(); i++) {
    answer.push_back(str1.at(i) + str2.at(i));
  }

  return answer;
}

std::vector<std::string> getNumber(int number) {
  std::vector<std::string> answer;
  switch (number) {
    case 0: {
      answer = {
        " 0000 ",
        "00  00",
        "00  00",
        "00  00",
        " 0000 " 
      };
      return answer;
      break;
    }
    case 1: {
      answer = {
        "1111  ",
        "  11  ",
        "  11  ",
        "  11  ",
        "111111" 
      };
      return answer;
      break;
    }
    case 2: {
      answer = {
        " 2222 ",
        "22  22",
        "   22 ",
        "  22  ",
        "222222"
      };
      return answer;
      break;
    }
    case 3: {
      answer = {
        " 3333 ",
        "33  33",
        "   333",
        "33  33",
        " 3333 "
      };
      return answer;
      break;
    }
    case 4: {
      answer = {
        "44  44",
        "44  44",
        "444444",
        "    44",
        "    44"
      };
      return answer;
      break;
    }
    case 5: {
      answer = {
        "555555",
        "55    ",
        "55555 ",
        "    55",
        "55555 "
      };
      return answer;
      break;
    }
    case 6: {
      answer = {
        " 6666 ",
        "66    ",
        "66666 ",
        "66  66",
        " 6666 "
      };
      return answer;
      break;
    }
    case 7: {
      answer = {
        "777777",
        "   77 ",
        "  77  ",
        " 77   ",
        "77    "
      };
      return answer;
      break;
    }
    case 8: {
      answer = {
        " 8888 ",
        "88  88",
        " 8888 ",
        "88  88",
        " 8888 "
      };
      return answer;
      break;
    }
    case 9: {
      answer = {
        " 9999 ",
        "99  99",
        " 99999",
        "    99",
        " 9999 "
      };
      return answer;
      break;
    }
    case 10: {
      answer = {
        "      ",
        "  00  ",
        "      ",
        "  00  ",
        "      "
      };
      return answer;
      break;
    }
  }
  return answer;
}

void displayTime() {
  time_t now = time(0);
  tm *time = localtime(&now);
  
  std::vector<std::string> sTime = getNumber(floor(time->tm_hour/10));
  sTime = addStringVector(sTime, getNumber(time->tm_hour - floor(time->tm_hour/10) * 10));
  sTime = addStringVector(sTime, getNumber(10));

  sTime = addStringVector(sTime, getNumber(floor(time->tm_min/10)));
  sTime = addStringVector(sTime, getNumber(time->tm_min - floor(time->tm_min/10) * 10));
  sTime = addStringVector(sTime, getNumber(10));

  sTime = addStringVector(sTime, getNumber(floor(time->tm_sec/10)));
  sTime = addStringVector(sTime, getNumber(time->tm_sec - floor(time->tm_sec/10) * 10));

  for (int i = 0; i < sTime.size(); i++) {
    for (int j = 0; j < sTime.at(0).size(); j++) {
      std::cout << sTime.at(i).at(j);
    }
    std::cout << '\n';
  }
}
