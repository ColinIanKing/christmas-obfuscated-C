YEARS = 2012 2013 2014 2015 2016 2017 2018 2019 2020

all:
	$(foreach Y,$(YEARS),$(MAKE) -C $(Y);)

clean:
	$(foreach Y,$(YEARS),$(MAKE) -C $(Y) clean;)

install:
	$(foreach Y,$(YEARS),$(MAKE) -C $(Y) install;)
