# Section #8

## Shorts

- [Week 8 Shorts Playlist](https://www.youtube.com/playlist?list=PLhQjrBD2T383avGUWA_h8DeDDSleg8eh_)

## Outline

- SQL

### SQL

- These are the data types shown in class:
  - INTEGER: smallint, integer, bigint
  - NUMERIC: boolean, date, datetime, numeric(scale, precision), time, timestamp
  - REAL: real, double precision
  - TEXT: char(n), varchar(n), text

- There are four basic `SQL` queries:
- `UPDATE`: Update data in a database table

```sql
UPDATE table SET col1 = val1, col2 = val2, ... # update table, changing values in particular columns

UPDATE table SET col1 = val1 WHERE identifier = "name" # update table, changing col1 to val1 where "name" equals "identifier"
```

- `INSERT INTO`: Insert values into a table

```sql
INSERT INTO table VALUES values # insert into table the row of values

INSERT INTO table (col1, col2) VALUES (val1, val2) # insert into table under columns col1 & col2, val1 & val2
```

- `SELECT`: Select values to view

```sql
SELECT col FROM table WHERE col = "identifier" # select a column from table to compare/ view

SELECT * FROM table # select all columns from a table
```

- `DELETE`: Delete from table

```sql
DELETE FROM table WHERE col = "identifier" # delete a row from table
```

- You can do this in Python using the method we've provided, `db.execute()`, which is the Python equivalent of `CS50::query()`, the PDO/PHP version of this from past years.
- Instead of using MySQL, we use SQLite, to keep the database in `.db` files within working directories, instead of requiring export.
- We also use `phpliteadmin` as our web-based interface, replacing `phpmyadmin`. To start `phpliteadmin`, pass in a database file as a parameter, and then click on the link that appears in your IDE's prompt.

```
$ phpliteadmin test.db
```

- This will open up `test.db` in `phpliteadmin`, allowing you to create database therein and perform any of the above database operations, among others.

## Quiz Review

- [These notes](https://github.com/austin-hwang/cs50-section)
- [CS50 Shorts](https://www.youtube.com/playlist?list=PLhQjrBD2T381k8ul4WQ8SQ165XqY149WW)
- study.cs50.net
- [Past exams](https://docs.cs50.net/2018/fall/quiz/about.html)

## Life after 50


You can find concentration requirements for CS [here](https://harvardcs.info/concentration/requirements/).

You can find CS courses after CS50 [here](https://cdn.cs50.net/guide/guide-18.pdf).
