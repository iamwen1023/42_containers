#include <iostream>
#include <ctime>
#include <map>
#include <stack>
#include <vector>
#include <deque>

#include <stdlib.h>
#include <fstream>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main()
{
    // Record the start time
    clock_t start_time = clock();

    // Some code to be timed
	{
		std::vector<std::string> vector_str;
		std::vector<int> vector_int;
		std::stack<int> stack_int;
		std::vector<Buffer> vector_buffer;
		std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
		std::map<int, int> map_int;

		for (int i = 0; i < COUNT; i++)
		{
			vector_buffer.push_back(Buffer());
		}

		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer[idx].idx = 5;
		}
		std::vector<Buffer>().swap(vector_buffer);

		try
		{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
		}
		catch(const std::exception& e)
		{
			//NORMAL ! :P
		}
		
		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(std::make_pair(rand(), rand()));
		}

		int sum = 0;
		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum += map_int[access];
		}
		std::ofstream myfile;
  		myfile.open ("f2.txt");
  		myfile << "Writing this to a file.\n";
		for(std::map<int, int>::iterator it=map_int.begin(); it != map_int.end(); it++){
			myfile << it->first << ",";
		}
		std::cout << "should be constant with the same seed: " << sum << std::endl;

		{
			std::map<int, int> copy = map_int;
		}
	}

    // Record the end time
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;

    return 0;
}