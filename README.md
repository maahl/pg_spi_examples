# Example usage of Postgres SPI and extension tools

This PostgreSQL extension does nothing special, except give some simple examples
of how to use postgres' Server Programming Interface (SPI), since I felt a lack
of examples while working on other projects.

This was made mainly by trial and error, so there might be inefficencies, or
mistakes. Use at your own risk!

It is nowhere near exhaustive, it merely showcases functions I've needed.

Pull requests are welcome!

## Resources
* [the official SPI documentation](https://www.postgresql.org/docs/current/static/spi.html)
* [the official C functions documentation](https://www.postgresql.org/docs/current/static/xfunc-c.html)
* [a tutorial on how to make postgres extensions](http://big-elephants.com/2015-10/writing-postgres-extensions-part-i/)  
  Note that this is only the first part in a series of 5 blog posts on the same
  topic (the link to the next post is at the bottom of the current post)

## Functions
* `pg_spi_int()`: insert an INT in a table
* `pg_spi_char()`: insert a CHAR(n) in a table
* `pg_spi_bit()`: insert a BIT(n) in a table
