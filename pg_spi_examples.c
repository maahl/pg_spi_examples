// this include should come first
#include "postgres.h"

#include "access/hash.h"
#include "catalog/pg_type.h"
#include "executor/spi.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

void _PG_init(void);
void _PG_fini(void);

PG_FUNCTION_INFO_V1(pg_spi_int);
PG_FUNCTION_INFO_V1(pg_spi_char);
PG_FUNCTION_INFO_V1(pg_spi_bit);
Datum pg_spi_int(PG_FUNCTION_ARGS);
Datum pg_spi_char(PG_FUNCTION_ARGS);
Datum pg_spi_bit(PG_FUNCTION_ARGS);

// function executed when the library is loaded
void _PG_init(void)
{
}


// insert an int in a table
Datum pg_spi_int(PG_FUNCTION_ARGS)
{
    char* query = "INSERT INTO pgspiexamples.pg_spi_examples (a) VALUES ($1);";
    const int num_args = 1;
    char* arg_nulls = " ";

    Oid arg_types[] = { INT4OID };
    Datum arg_values[] = { Int32GetDatum(123) };

    SPI_connect();
    SPI_execute_with_args(query, num_args, arg_types, arg_values, arg_nulls, false, 0);
    SPI_finish();

    PG_RETURN_VOID();
}


// insert a char
Datum pg_spi_char(PG_FUNCTION_ARGS)
{
    char* query = "INSERT INTO pgspiexamples.pg_spi_examples (b) VALUES ($1);";
    const int num_args = 1;
    char* arg_nulls = " ";

    Oid arg_types[] = { BPCHAROID };
    Datum arg_values[] = { CStringGetTextDatum("test") };

    SPI_connect();
    SPI_execute_with_args(query, num_args, arg_types, arg_values, arg_nulls, false, 0);
    SPI_finish();

    PG_RETURN_VOID();
}


// insert a bit(32)
Datum pg_spi_bit(PG_FUNCTION_ARGS)
{
    char* query = "INSERT INTO pgspiexamples.pg_spi_examples (c) VALUES ($1::BIT(32));";
    const int num_args = 1;
    char* arg_nulls = " ";

    char* test = "test";
    // we cast the bit(32) to an int to avoid weird segfaults that i couldn't
    // solve if I tried to insert a BITOID directly
    Oid arg_types[] = { INT4OID };
    Datum arg_values[] = { hash_any((unsigned char*) test, sizeof(test)) };

    // note that hash_any() is said to return a uint32, but this type is not available in sql
    elog(LOG, "pg_spi_examples: hash value %i", DatumGetInt32(arg_values[0]));

    SPI_connect();
    SPI_execute_with_args(query, num_args, arg_types, arg_values, arg_nulls, false, 0);
    SPI_finish();

    PG_RETURN_VOID();
}


// function executed when the library is unloaded
void _PG_fini(void)
{
}
