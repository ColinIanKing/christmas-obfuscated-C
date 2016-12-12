YEARS = 2012 2013 2014 2015 2016

all:
	$(foreach Y,$(YEARS),$(MAKE) -C $(Y);)

clean:
	$(foreach Y,$(YEARS),$(MAKE) -C $(Y) clean;)

