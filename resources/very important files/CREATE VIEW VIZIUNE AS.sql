CREATE VIEW VIZIUNE AS
SELECT * FROM EMPLOYEES;

CREATE VIEW VIZIUNE_2 AS
SELECT START_DATE, END_DATE FROM JOB_HISTORY;

CREATE VIEW VIZIUNE_3 AS
SELECT * FROM LOCATIONS WHERE LOCATION_ID BETWEEN 1700 AND 2800 OR LENGTH(CITY) < 7;

CREATE VIEW VIZIUNE_4 AS 
SELECT * FROM
VIZIUNE NATURAL JOIN VIZIUNE_2 NATURAL JOIN VIZIUNE_3;

CREATE VIEW VIZIUNE_5 AS
SELECT e.employee_id, e.first_name, d.department_name, l.city, c.country_name, r.region_name, j.job_title
FROM employees e JOIN departments d ON e.department_id = d.department_id
JOIN jobs j ON e.job_id = j.job_id JOIN locations l ON d.location_id = l.location_id
JOIN countries c ON l.country_id = c.country_id JOIN regions r ON c.region_id = r.region_id;

CREATE OR REPLACE VIEW VIZIUNE_5 AS
SELECT
    e.employee_id,
    e.first_name,
    e.last_name, -- Coloană adăugată
    d.department_name,
    l.city,
    c.country_name,
    r.region_name,
    j.job_title
FROM
    employees e
    JOIN departments d ON e.department_id = d.department_id
    JOIN jobs j ON e.job_id = j.job_id
    JOIN locations l ON d.location_id = l.location_id
    JOIN countries c ON l.country_id = c.country_id
    JOIN regions r ON c.region_id = r.region_id;

CREATE OR REPLACE VIEW VIZIUNE_5 AS
SELECT
    e.employee_id,
    e.first_name,
    -- e.last_name, linie modificata
    d.department_name,
    l.city,
    c.country_name,
    r.region_name,
    j.job_title
FROM
    employees e
    JOIN departments d ON e.department_id = d.department_id
    JOIN jobs j ON e.job_id = j.job_id
    JOIN locations l ON d.location_id = l.location_id
    JOIN countries c ON l.country_id = c.country_id
    JOIN regions r ON c.region_id = r.region_id;

CREATE OR REPLACE VIEW VIZIUNE_3 AS
SELECT * FROM LOCATIONS;

DROP VIEW VIZIUNE;

GRANT SELECT on VIZIUNE_2 to c##Valera;