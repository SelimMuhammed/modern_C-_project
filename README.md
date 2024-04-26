# modern_Cpp_project

This Markdown document provides documentation for the provided C++ code.

## Code Overview

The provided C++ code demonstrates a simple program for managing a database of persons. Users can add records, fetch records by ID, and quit the program.

## Libraries Used

- `iostream`: For input and output operations.
- `string`: For string manipulation.
- `array`: For defining an array of options.
- `vector`: For storing person records in a dynamic array.
- `limits`: For handling numeric limits.

## Macros Defined

- `OPTIONS_MAX_NUM`: Specifies the maximum number of options available.
- `INIT_VALUE`: Specifies the initial value.

## Enumerations

### `option`

- Enumerates the options available in the program:
  - `AddRecord`: Adds a record.
  - `FetchRecord`: Fetches a record.
  - `Quit`: Quits the program.

## Functions

### `convertToStr`

- Converts the `option` enum to a string representation.

### `Add_voidRecord`

- Adds a new record to the `PersonDB` vector.

### `Fetch_personRecord`

- Fetches a person record based on the provided user ID.

### `operator>>`

- Overloads the input stream operator to read an option enum.

## Class

### `Person`

- Represents a person with name and age attributes.
- Contains an array of available options.
- Provides a method to display available options.

## Global Variables

- `PersonDB`: Vector to store person records.

## Main Function

- Accepts user input to select options until the user chooses to quit.
- Handles adding a record, fetching a record, and quitting the program.

## Usage

- Compile the code and run the executable.
- Follow the on-screen instructions to interact with the program.
- Select options to add records, fetch records, or quit.

