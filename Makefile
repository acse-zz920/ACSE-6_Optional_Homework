CXX = g++
TARGETS = task_1 task_2 task_3 task_4 task_4a task_4b
CFLAGS = -fopenmp
LDFLAGS = -lm

all: $(TARGETS)

task_1: main_task1.cc
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

task_2: main_task2.cc
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

task_3: main_task3.cc
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

task_4: main_task4.cc
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

task_4a: main_task4a.cc
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

task_4b: main_task4b.cc
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	-rm -rf $(TARGETS)
