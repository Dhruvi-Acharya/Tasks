cmake_minimum_required(VERSION 3.0)
project(Tasks)

add_executable(
	Tasks
	libraryApplication.cpp
	src/Books.cpp
	src/LibBooks.cpp
	include/Books.h
	include/LibBooks.h
	)