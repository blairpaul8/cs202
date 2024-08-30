import subprocess
import re

# List of test case files
test_files = [f'test{i}.txt' for i in range(1, 9)]

# Path to your compiled C++ program
compiled_program = './main'

# Regular expression pattern to match "X wins!" or "O wins!"
pattern = re.compile(r'(X|O) Wins?', re.IGNORECASE)

# Expected correct answers for each test case
correct_answers = {
    'test1.txt': 'X Wins',
    'test2.txt': 'X Wins',
    'test3.txt': 'X Wins',
    'test4.txt': 'X Wins',
    'test5.txt': 'X Wins',
    'test6.txt': 'X Wins',
    'test7.txt': 'X Wins',
    'test8.txt': 'O Wins',
}

# Loop through each test case and pipe it to the compiled program
for test_file in test_files:
    with open(test_file, 'r') as f:
        # Run the compiled program and pipe the content of the test file
        result = subprocess.run(compiled_program, stdin=f, capture_output=True, text=True)
        
        # Search for the pattern in the output
        match = pattern.search(result.stdout)
        
        if match:
            correct_answer = correct_answers[test_file]
            # Print the matched line followed by the correct answer, with 10 spaces in between
            print(f'Result for {test_file}: {match.group()}{ " " * 10 }Correct answer: {correct_answer}')
        else:
            print(f'Result for {test_file}: No winner found')
        
        print('-' * 60)
