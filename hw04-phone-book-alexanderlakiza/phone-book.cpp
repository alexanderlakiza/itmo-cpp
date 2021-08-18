#include "phone-book.h"
#include <algorithm>
bool phone_book_t::create_user(const std::string &number, const std::string &name) {
  for (auto &user : users) {
    if (number == user.user.number) {
      return false;
    }
  }
  user_t user_new{number, name};
  user_info_t contact_new{user_new};
  users.push_back(contact_new);
  return true;
}

bool phone_book_t::add_call(const call_t &call) {
  auto call_number = call.number;
  for (auto &user_info : users) {
    if (user_info.user.number == std::string(call_number)) {
      calls.push_back(call);
      user_info.total_call_duration_s += call.duration_s;
      return true;
    }
  }
  return false;
}

std::vector<call_t> phone_book_t::get_calls(size_t start_pos, size_t count) const {
  if (int(start_pos) >= calls.size()) {
    return std::vector<call_t>{};
  }
  if (int(start_pos) + int(count) >= calls.size()) {
    return std::vector<call_t>(calls.begin() + int(start_pos), calls.end());
  }
  return std::vector<call_t>(calls.begin() + int(start_pos), calls.begin() + int(start_pos) + int(count));
}

bool name_comp(const user_info_t &user1, const user_info_t &user2) {
  return (user1.user.name < user2.user.name) ||
         (user1.user.name == user2.user.name && user1.total_call_duration_s > user2.total_call_duration_s) ||
         (user1.user.name == user2.user.name && user1.total_call_duration_s == user2.total_call_duration_s &&
          user1.user.number < user2.user.number);
}

bool numb_comp(const user_info_t &user1, const user_info_t &user2) {
  return (user1.total_call_duration_s > user2.total_call_duration_s) ||
         ((user1.total_call_duration_s == user2.total_call_duration_s) && (user1.user.name < user2.user.name)) ||
         ((user1.total_call_duration_s == user2.total_call_duration_s) && (user1.user.name == user2.user.name) &&
          (user1.user.number < user2.user.number));
}

std::vector<user_info_t> phone_book_t::search_users_by_name(const std::string &name_prefix, size_t count) const {
  std::vector<user_info_t> users_searched{};
  for (const auto &user : users) {
    if (user.user.name.find(name_prefix) == 0) {
      users_searched.push_back(user);
    }
  }
  std::sort(users_searched.begin(), users_searched.end(), name_comp);
  if (users_searched.size() <= int(count)) {
    return users_searched;
  } else {
    return std::vector<user_info_t>(users_searched.begin(), users_searched.begin() + int(count));
  }
}

std::vector<user_info_t> phone_book_t::search_users_by_number(const std::string &number_prefix, size_t count) const {
  std::vector<user_info_t> users_searched{};
  for (const auto &user : users) {
    if (user.user.number.find(number_prefix) == 0) {
      users_searched.push_back(user);
    }
  }
  std::sort(users_searched.begin(), users_searched.end(), numb_comp);
  if (users_searched.size() <= int(count)) {
    return users_searched;
  } else {
    return std::vector<user_info_t>(users_searched.begin(), users_searched.begin() + int(count));
  }
}

void phone_book_t::clear() {
  users.clear();
  calls.clear();
}

size_t phone_book_t::size() const {
  return users.size();
}

bool phone_book_t::empty() const {
  return users.empty();
}
