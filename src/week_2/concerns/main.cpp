#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>

const std::string OP_ADD = "ADD";
const std::string OP_DUMP = "DUMP";
const std::string OP_NEXT = "NEXT";

enum Months {
  Jan = 1,
  Feb,
  March,
  April,
  May,
  June,
  July,
  August,
  Sep,
  Oct,
  Nov,
  Dec,
};

Months &operator++(Months &month);

// days_in_month contains number of days in each month.
// February *always* has 28 days.
const std::map<Months, int> days_in_month = {
    {Jan, 31},  {Feb, 28},    {March, 31}, {April, 30}, {May, 31}, {June, 30},
    {July, 31}, {August, 31}, {Sep, 30},   {Oct, 31},   {Nov, 30}, {Dec, 31},
};

// get_days_in_month returns number of days in month.
int get_days_in_month(Months m) {
  auto ndays = days_in_month.at(m);
  return ndays;
}

int main() {
  int noperations = 0;
  std::cin >> noperations;

  auto current_month = Months::Jan;
  std::vector<std::vector<std::string>> concerns(
      get_days_in_month(current_month));

  for (auto i = 0; i < noperations; ++i) {
    std::string op;
    std::cin >> op;

    if (op == OP_ADD) {
      int day = 0;
      std::string task;
      std::cin >> day >> task;

      if (day > get_days_in_month(current_month))
        continue;

      auto day_idx = day == 0 ? 0 : day - 1;
      concerns[day_idx].push_back(task);

      continue;
    }

    if (op == OP_DUMP) {
      int day = 0;
      std::cin >> day;

      if (day > get_days_in_month(current_month))
        continue;

      auto day_idx = day == 0 ? 0 : day - 1;
      auto ntasks = concerns[day_idx].size();

      std::cout << ntasks;
      if (ntasks > 0) {
        for (const auto &t : concerns[day_idx])
          std::cout << " " << t;
      }
      std::cout << std::endl;

      continue;
    }

    if (op == OP_NEXT) {
      auto prev_month = current_month;
      ++current_month;

      auto nprevdays = get_days_in_month(prev_month);
      auto ncurdays = get_days_in_month(current_month);
      auto common_day = std::min(nprevdays, ncurdays);

      std::vector<std::vector<std::string>> cur_concerns(ncurdays);
      for (auto j = 0; j < common_day; ++j) {
        cur_concerns[j] = concerns[j];
      }

      if (ncurdays < nprevdays) {
        // It is possible if and only if current month has less days than
        // previos.
        // I.e.: was Jan and then NEXT was called so `concerns` vector has 31
        // vectors of tasks and `cur_concerns` has 28 vectors of tasks. So that
        // we should add remaining vectors of tasks from day 29 (index 28) and
        // so on to day 28 (index 27) of `cur_concerns`.
        auto last_day_idx = common_day - 1;
        auto last_day_concerns = cur_concerns[last_day_idx];
        for (auto j = common_day; j < concerns.size(); ++j) {
          last_day_concerns.insert(last_day_concerns.end(), concerns[j].begin(),
                                   concerns[j].end());
        }
        cur_concerns[last_day_idx] = last_day_concerns;
      }

      concerns = cur_concerns;

      continue;
    }
  }

  return 0;
}

Months &operator++(Months &month) {
  switch (month) {
  case Months::Jan:
    return month = Months::Feb;
  case Months::Feb:
    return month = Months::March;
  case Months::March:
    return month = Months::April;
  case Months::April:
    return month = Months::May;
  case Months::May:
    return month = Months::June;
  case Months::June:
    return month = Months::July;
  case Months::July:
    return month = Months::August;
  case Months::August:
    return month = Months::Sep;
  case Months::Sep:
    return month = Months::Oct;
  case Months::Oct:
    return month = Months::Nov;
  case Months::Nov:
    return month = Months::Dec;
  case Months::Dec:
    return month = Months::Jan;
  }
};
