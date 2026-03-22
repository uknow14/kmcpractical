-- 10. Write queries in SQL to
  
-- a. Create a database named KMC.
	
  create database KMC

-- b. Create a table named RESULT in KMC having field id, name and mark.
USE KMC;

CREATE TABLE RESULT (
    id INT,
    name VARCHAR(50),
    mark INT
); 	

-- c. Insert three records in it.
INSERT INTO RESULT VALUES (1, 'Ram', 75);
INSERT INTO RESULT VALUES (2, 'Sita', 45);
INSERT INTO RESULT VALUES (3, 'Hari', 32);

-- d. Display all data in a descending order according to mark.

SELECT * FROM RESULT ORDER BY mark DESC;

-- e. Display name of students who have failed.

SELECT name FROM RESULT WHERE mark < 40;

-- f. Find the average mark.

SELECT AVG(mark) AS AverageMark FROM RESULT;

-- g. Display details of student having the highest mark 
SELECT * FROM RESULT WHERE mark = (SELECT MAX(mark) FROM RESULT);
