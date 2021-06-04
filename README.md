# EntranceExamsResultProcessor
 One of the exercises for my Programming Language course at FATEC Mogi Mirim, which involves creating a program to process the results of a college or university entrance exam with 50 multiple choice questions.
## Input format
 The input follows the format   `CCCCC XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX`,  where `CCCCC` is the numeric **id** of entrance exam candidate and each `X` are the **answers** for each of the questions, which can be *a*, *b*, *c*, *d* or *e*.
 ## Input source
 Since the input source wasn't clear in the exercise description, the program supports file input and manual input, but not both at the same time.
### File input
 The program assumes that:
 - Each line in the input file will have:
	 - A variable length id, with no more than 5 digits;
	 - A 50 character length string for the candidate answers;
 - There's no duplicate ids.
### Manual input
 The program will ask the user to type:
- An id, which:
	- Can have no more than 5 digits;
	- Cannot be the same of a previously registered candidate.
- The answers for each of the 50 entrance exam questions, which can be typed sequentially, i.e., `abaecdaebcd…`

 After typing the candidate answers, the program will query ask if the user wants to register another candidate (Y/N).
## Output
The program outputs every registered candidate in the format `CCCCC XX`, where `CCCCC` is the candidate id and `XX` how many correct answers they got.