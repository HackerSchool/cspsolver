#ifndef ERROR_MESSAGE_H
#define ERROR_MESSAGE_H

#include <string>

const std::string EM_ID_NOT_FOUND = "id (integer) not found";
const std::string EM_ID_OUT_OF_BOUNDS = "id out of bounds";
const std::string EM_PROBLEM_VARSET_NULL = "variable set in null";
const std::string EM_PROBLEM_CONSET_NULL = "constraint set in null";
const std::string EM_VARID_ID_NOT_SETTED = "variable identifier does not have _id field initialized";
const std::string EM_MULT_WRONG_TYPES = "mult: wrong types";
const std::string EM_RANGE_TYPES = "range: wrong types";
const std::string EM_FILTER_TYPES = "filter: wrong types";
const std::string EM_VARIABLE_DOMAIN_NOT_SET = "variable domain is not a set";
const std::string EM_VARIABLE_NAME_NOT_FOUND = "this variable name was not found";
#endif