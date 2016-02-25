all:dates_as_strings days_alive
dates_as_strings:
	g++ dates_as_strings.cpp -odates_as_strings -lboost_date_time
days_alive:
	g++ days_alive.cpp -odays_alive -lboost_date_time
.PHONY:clean
clean:
	rm dates_as_strings days_alive