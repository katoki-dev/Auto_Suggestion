# Auto-Suggestion System

## Overview
This project implements an auto-suggestion system using C, utilizing linked lists and CSV file processing. It provides suggestions based on a vocabulary dataset.

## Features
- Reads vocabulary from a CSV file
- Implements a linked list for efficient searching
- Provides word suggestions dynamically

## File Structure
- **reading.c**: Main program logic
- **vocabulary.csv**: Contains words for suggestions
- **linkedlist.h**: Defines linked list structure and functions
- **operation.h**: Contains core operational functions
- **readcsv.h**: Handles reading CSV files

## Installation & Usage
1. Clone this repository:
   ```sh
   git clone https://github.com/katoki-dev/auto-suggestion.git
   cd auto-suggestion
   ```
2. Compile the program:
   ```sh
   gcc reading.c -o auto_suggest
   ```
3. Run the executable:
   ```sh
   ./auto_suggest
   ```

## Contributing
Feel free to fork this repository and submit pull requests for improvements.



