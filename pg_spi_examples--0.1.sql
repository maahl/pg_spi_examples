-- prevent execution of the script from psql
\echo Use "CREATE EXTENSION pg_spi_bit_example;" to load this file. \quit

SET client_encoding = 'UTF8';

CREATE TABLE pg_spi_examples (
    id SERIAL PRIMARY KEY,
    a INT,
    b CHAR(32),
    c BIT(32)
);

CREATE FUNCTION pg_spi_int()
    RETURNS void
    LANGUAGE c COST 100
AS '$libdir/pg_spi_examples', 'pg_spi_int';

CREATE FUNCTION pg_spi_char()
    RETURNS void
    LANGUAGE c COST 100
AS '$libdir/pg_spi_examples', 'pg_spi_char';

CREATE FUNCTION pg_spi_bit()
    RETURNS void
    LANGUAGE c COST 100
AS '$libdir/pg_spi_examples', 'pg_spi_bit';
