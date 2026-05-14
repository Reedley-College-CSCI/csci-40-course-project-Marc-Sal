[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Ay551EX-)
# CS1 Final Project - [Project Title]

## 1. Overview
- What problem does your project solve?  
- Briefly describe the purpose and key features of your program.  
My project will solve the problem of comic book collectors not being able to keep track 
of their invetory. It will keep the comics in a clean array. The user will be able to sort
the comics in by a lot of factors such as value. The user will also be able to remove and add 
comics.

---

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  
I used constructs as my main source of keeping track of the comics. It will use strings and a double
to keep track of it value and the many other factors such as the name and publisher to name a few.
- Why did you choose to structure your data using structs?  
I choose to use structs because I needed to group a lot of variables together. I needed to create a new 
data type that would fit the requirements that a comicBook has so a struct was the obvious answer.
- How did you implement searching and sorting? What algorithms did you use and why?  
I uses a sorting algorithms when it came to sorting the the list by value and used a searching algorithim
to find comics in a specific price range.
- How do you ensure data persistence between program runs?  
I will ensure that data persists between by using files and storing the data there. I have created a function 
that will allow the user to load in a file to use and then another function that will create a file that has 
been edited by the user using this program.
- Did you consider alternative approaches? If so, why did you not use them?  
I was initially planning on using classes instead of a struct due to the many functions but decided to instead
to use structs as it wsas easier to use and I had more experience with it.

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  
// TestCase ID|	 Description	| Input Code Snippet   | Expected Output	 | Actual Output		 | Pass/Fail|
// TC-01      |File doesn't     |loadFile(comics, z,   |Should print         |"Unable to load file"	 |Fail	    |
//            |exist            |size);                |"Unable to load file"| but did not reprompt	 |		    |
//            |                 |                      |and prompt again	 |					     |		    |
// _____________________________________________________________________________________________________________
// TC-02      |Invalid Menu     |cin >> choice         |Should print "Invalid|Printed "Invalid input.|Pass      |
//            |option			|                      |input. Please make   |Please make entry is   |          |
//            |                 |                      |entry is capitalized"|capatalized"           |          |
// _____________________________________________________________________________________________________________
// TC-03      |Invalid Menu     |cin >> choice2        |Should print "Invalid|Printed "Invalid input.|Pass      |
//            |option			|                      |input. Please make   |Please make entry is   |          |
//            |                 |                      |entry is capitalized"|capatalized"           |          |
//__________________________________________________________________________________________________________
// TC-04      |Author doesn't   |searchAuthor(comics,  |Should print nothing |Printed nothing        |Pass      |
//            |exist            |"nobody", size);      |                     |                       |          |
//            |                 |                      |                     |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________
// TC-05      |Comic doesn't    |searchComicName(      |Should print nothing |Printed nothing        |Pass      |
//            |exist            |comics, "nobody", size|                     |                       |          |
//            |                 |);                    |                     |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________
// TC-06      |Publisher doesn't|searchPublisher(      |Should print nothing |Printed nothing        |Pass      |
//            |exist            |comics, "nobody", size|                     |                       |          |
//            |                 |);                    |                     |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________
// TC-07      |Nothing in price |searchPublisher(      |Should print nothing |Printed nothing        |Pass      |
//            |range exists     |comics, 10000, 20000, |                     |                       |          |
//            |                 |size);                |                     |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________
// TC-08      |Incorrect data   |cin >> check;         |Should handle the    |Repeats the prompt     |Fail      |
//            |type input       |Incorrect data type   |entry with out       |infinitely             |          |
//            |                 |entry for check       |crashing             |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________
// TC-09      |Incorrect data   |cin >> size;          |Should handle the    |Doesn't crash and      |Pass      |
//            |type input       |Incorrect data type   |entry with out       |prompts the user again |          |
//            |                 |entry for size        |crashing and prompt  |                       |          |
//            |                 |                      |the user again       |                       |          |
//__________________________________________________________________________________________________________
// TC-10      |Incorrect data   |cin >> maxPrice;      |Should handle the    |Doesn't crash and      |Pass      |
//            |type input       |Incorrect data type   |entry with out       |prompts the user again |          |
//            |                 |entry for maxPrice    |crashing and prompt  |                       |          |
//            |                 |                      | the user again      |                       |          |
//__________________________________________________________________________________________________________
// TC-11      |Incorrect data   |cin >> minPrice;      |Should handle the    |Doesn't crash and      |Pass      |
//            |type input       |Incorrect data type   |entry with out       |prompts the user again |          |
//            |                 |entry for minPrice    |crashing and prompt  |                       |          |
//            |                 |                      |the user again       |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________
// TC-12      |negative number  |cin >> size;          |Should handle the    |Crashes                |Fail      |
//            |for size         |size < 0              |entry with out       |                       |          |
//            |                 |                      |crashing and prompt  |                       |          |
//            |                 |                      |the user again       |                       |          |
//            |                 |                      |                     |                       |          |
//__________________________________________________________________________________________________________




---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.

---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
- What key lessons did you learn about programming and problem-solving?  

---

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  
