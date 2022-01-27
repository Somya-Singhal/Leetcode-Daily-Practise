# Write your MySQL query statement below
# select max(salary) as SecondHighestSalary
# from Employee
# where salary NOT IN (select max(salary) from Employee);

select 
 (select distinct salary
       from Employee
       order by salary desc
       LIMIT 1 OFFSET 1) as SecondHighestSalary;