# Spell Check Tool with Data Structures

## Project Overview

This project is a spell check tool designed to help users correct misspelled words using various data structures and algorithms. It reads a list of commonly used English words from a "vocabulary.txt" file and stores them in a linked list. Users can interact with the tool through different modes, each serving a specific purpose.

## Modes of Operation

### 1. Print First "n" Words

- **Description**: This mode allows the user to verify the correct implementation of the linked list by printing the first "n" words from the list.
- **Usage**: Specify the value of "n" to print the desired number of words.

### 2. Calculate Edit Distance for Misspelled Word

- **Description**: This mode checks the correctness of the minimum edit distance algorithm. The user provides a misspelled word, and the tool calculates the edit distance between the misspelled word and the first "n" words in the list.
- **Usage**: Enter a misspelled word and specify the value of "n."

### 3. Generate Word Suggestions for Misspelled Word

- **Description**: In this mode, the tool provides word suggestions for a misspelled word. It identifies "n" words from the list with the lowest edit distance scores to the misspelled word. If multiple words share the same edit distance score, the tool selects the first occurrences from the list.
- **Usage**: Enter a misspelled word and specify the value of "n."
