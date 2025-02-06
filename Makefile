pa11: Athlete.o olympian.o pa11.o
	$(CXX) $(CXXFLAGS) Athlete.o olympian.o pa11.o -o pa11

Athlete.o: Athlete.cpp Athlete.h
	$(CXX) $(CXXFLAGS) -c Athlete.cpp

olympian.o: olympian.cpp olympian.h Athlete.h
	$(CXX) $(CXXFLAGS) -c olympian.cpp

pa11.o: pa11.cpp olympian.h Athlete.h

clean:
	rm -f *.o pa11
