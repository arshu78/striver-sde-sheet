# Write your MySQL query statement below
select u.unique_id,e.name from Employees as e lEFT JOIN EmployeeUNI as u on e.id=u.id;