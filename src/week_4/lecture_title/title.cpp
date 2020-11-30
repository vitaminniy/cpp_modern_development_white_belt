#include <string>

struct Specialization {
  explicit Specialization(std::string s) { specialization = s; }

  std::string specialization;
};

struct Course {
  explicit Course(std::string s) { course = s; }

  std::string course;
};

struct Week {
  explicit Week(std::string s) { week = s; }

  std::string week;
};

struct LectureTitle {
  LectureTitle(const Specialization &s, const Course &c, const Week &w) {
    specialization = s.specialization;
    course = c.course;
    week = w.week;
  }

  std::string specialization;
  std::string course;
  std::string week;
};

