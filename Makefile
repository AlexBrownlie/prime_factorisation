CXX-flags = -O3 -std=c++11 -Wall

Reference = primeFactorisation-Reference.o
BestStudent = primeFactorisation-BestStudent.o
MyImplementation = primeFactorisation.cpp

Timing = timingTests.cpp
Correct = correctnessTests.cpp

AllFiles = correctnessTests_BestStudent.exe correctnessTests_Reference.exe timingTests_BestStudent.exe timingTests_Reference.exe correctnessTests_Mine.exe timingTests_Mine.exe


all : ${AllFiles} 


timingTests_Reference.exe : ${Timing} ${Reference} 
	g++ ${CXX-flags} ${Timing} ${Reference} -o timingTests_Reference.exe


timingTests_BestStudent.exe : ${Timing} ${BestStudent} 
	g++ ${CXX-flags}  ${Timing} ${BestStudent} -o timingTests_BestStudent.exe


correctnessTests_Reference.exe : ${Correct} ${Reference}
	g++ ${CXX-flags}  ${Correct} ${Reference} -o correctnessTests_Reference.exe


correctnessTests_BestStudent.exe : ${Correct} ${BestStudent} 
	g++ ${CXX-flags}  ${Correct} ${BestStudent} -o correctnessTests_BestStudent.exe


correctnessTests_Mine.exe : ${Correct} ${MyImplementation}
	g++ ${CXX-flags}  ${Correct} ${MyImplementation} -o correctnessTests_Mine.exe

timingTests_Mine.exe : ${Timing} ${MyImplementation}
	g++ ${CXX-flags}  ${Timing} ${MyImplementation} -o timingTests_Mine.exe


clean :
	rm ${AllFiles}

	
