# DMBS LAB

## Part A: SQL Programming

**1. Consider the following schema for a Library Database:**  

```sql
CREATE TABLE BOOK(Book_id, Title, Publisher_Name, Pub_Year) 
CREATE TABLE BOOK_AUTHORS(Book_id, Author_Name)  
CREATE TABLE PUBLISHER(Name, Address, Phone)  
CREATE TABLE BOOK_COPIES(Book_id, Branch_id, No-of_Copies)  
CREATE TABLE BOOK_LENDING(Book_id, Branch_id, Card_No, Date_Out, Due_Date)  
CREATE TABLE LIBRARY_BRANCH(Branch_id, Branch_Name, Address)  
```

_Write SQL queries to_

```
1. Retrieve details of all books in the library – id, title, name of publisher, authors,  
   number of copies in each branch, etc.    
2. Get the particulars of borrowers who have borrowed more than 3 books, but from Jan 2017 to Jun 2017.  
3. Delete a book in BOOK table. Update the contents of other tables to reflect this data manipulation operation.  
4. Partition the BOOK table based on year of publication. Demonstrate its working with a simple query.    
5. Create a view of all books and its number of copies that are currently available in the Library.  
```

**2 - Consider the following schema for Order Database:**  


```sql
CREATE TABLE SALESMAN(Salesman_id, Name, City, Commission)
CREATE TABLE CUSTOMER(Customer_id, Cust_Name, City, Grade, Salesman_id)
CREATE TABLE ORDERS(Ord_No, Purchase_Amt, Ord_Date, Customer_id, Salesman_id)
```


_Write SQL queries to_

```
1. Count the customers with grades above Bangalore’s average.  
2. Find the name and numbers of all salesman who had more than one customer.  
3. List all the salesman and indicate those who have and don’t have customers in
   their cities (Use UNION operation.)  
4. Create a view that finds the salesman who has the customer with the highest
   order of a day.  
5. Demonstrate the DELETE operation by removing salesman with id 1000. All
   his orders must also be deleted.  
```


**3 - Consider the schema for Movie Database:**  

```sql
CREATE TABLE ACTOR(Act_id, Act_Name, Act_Gender)
CREATE TABLE DIRECTOR(Dir_id, Dir_Name, Dir_Phone)
CREATE TABLE MOVIES(Mov_id, Mov_Title, Mov_Year, Mov_Lang, Dir_id)
CREATE TABLE MOVIE_CAST(Act_id, Mov_id, Role)
CREATE TABLE RATING(Mov_id, Rev_Stars)
```


_Write SQL queries to_

```
1. List the titles of all movies directed by ‘Hitchcock’.  
2. Find the movie names where one or more actors acted in two or more movies.  
3. List all actors who acted in a movie before 2000 and also in a movie after 2015 (use JOIN operation).  
4. Find the title of movies and number of stars for each movie that has at least one rating  
   and find the highest number of stars that movie received. Sort the result by movie title.  
5. Update rating of all movies directed by ‘Steven Spielberg’ to 5.  
```

**4 - Consider the schema for College Database:**  

```sql
CREATE TABLE STUDENT(USN, SName, Address, Phone, Gender)
CREATE TABLE SEMSEC(SSID, Sem, Sec)
CREATE TABLE CLASS(USN, SSID)
CREATE TABLE SUBJECT(Subcode, Title, Sem, Credits)
CREATE TABLE IAMARKS(USN, Subcode, SSID, Test1, Test2, Test3, FinalIA)
```


_Write SQL queries to_

```
1. List all the student details studying in fourth semester ‘C’ section.   
2. Compute the total number of male and female students in each semester and in each section.  
3. Create a view of Test1 marks of student USN ‘1BI15CS101’ in all subjects.  
4. Calculate the FinalIA (average of best two test marks) and update the corresponding table for all students.  
5. Categorize students based on the following criterion:  
   If FinalIA = 17 to 20 then CAT = ‘Outstanding’  
   If FinalIA = 12 to 16 then CAT = ‘Average’  
   If FinalIA< 12 then CAT = ‘Weak’  
   Give these details only for 8th semester A,B, and C section students.    
```


**5 - Consider the schema for Company Database:**    

```sql
CREATE TABLE EMPLOYEE(SSN, Name, Address, Sex, Salary, SuperSSN, DNo)
CREATE TABLE DEPARTMENT(DNo, DName, MgrSSN, MgrStartDate)
CREATE TABLE DLOCATION(DNo,DLoc)
CREATE TABLE PROJECT(PNo, PName, PLocation, DNo)
CREATE TABLE WORKS_ON(SSN, PNo, Hours)
```

_Write SQL queries to_

```
1. Make a list of all project numbers for projects that involve an employee whose last name is ‘Scott’,  
   either as a worker or as a manager of the department that controls the project.  
2. Show the resulting salaries if every employee working on the ‘IoT’ project is given a 10 percent raise.  
3. Find the sum of the salaries of all employees of the ‘Accounts’ department, as well as the maximum salary,  
   the minimum salary, and the average salary in this department.  
4. Retrieve the name of each employee who works on all the projects controlledby department number 5 (use NOT EXISTS operator).  
5. For each department that has more than five employees, retrieve the department number and the number  
   of its employees who are making more than Rs. 6,00,000.  
```

## Part B: Mini project
