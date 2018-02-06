EXTENSION = pg_spi_examples
MODULES = pg_spi_examples
DATA = $(wildcard *--*.sql)

# postgresql build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
