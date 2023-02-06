#pragma once

#include <functional>
#include <iostream>
#include <map>

// invoking functions
namespace example_0
{
	void print(int val)
	{
		std::cout << val << '\n';
	}

	std::function<void(int)> func{ print };

	void run(void)
	{
		func(42);
		std::invoke(func, 42);		// same as func(42)
	}
}

namespace example_1
{
	std::function<void(int)> func{ [](int val) { std::cout << val << '\n'; } };

	void run(void)
	{
		func(42);
		std::invoke(func, 42);		// same as func(42)
	}
}

namespace example_2
{
	struct S
	{
		S() :v{ 0 } {}
		void do_something(int val)
		{
			v += val;
			std::cout << v << '\n';
		}

		int v;
	};

	void run(void)
	{
		S s;

		std::invoke(&S::do_something, s, 20);			// same as s.do_something(20)
		std::invoke(&S::do_something, std::ref(s), 20);	// same as s.do_something(20)

		S* p = &s;
		std::invoke(&S::do_something, p, 20);			// same as p->do_something(20)
	}
}

namespace example_3
{
	struct S
	{
		S() :v{ 0 } {}

		void do_something()
		{	
			std::cout << "hello 1\n";
		}
		int v;
	};


	void run(void)
	{
		S s;

		std::invoke(&S::do_something, s);				// same as s.do_something();
	}
}

namespace example_4
{
	struct S
	{
		S() :v{ 0 } {}

		std::function<void()> do_something;
		int v;
	};

	void run(void)
	{
		S s;
		s.do_something = []() { std::cout << "hello 2\n"; };

		std::invoke(&S::do_something, s);				// same as s.do_something;
		std::invoke(&S::do_something, s)();				// same as s.do_something();
		std::invoke(std::invoke(&S::do_something, s));	// same as s.do_something();
	}
}

namespace example_5
{
	struct S
	{
		S(std::function<void()> func) : do_something{ func } {}

		std::function<void()> do_something;
	};

	void run(void)
	{
		S s{ []() { std::cout << "hello 3\n"; } };

		std::invoke(&S::do_something, s);				// same as s.do_something;
		std::invoke(&S::do_something, s)();				// same as s.do_something();
		std::invoke(std::invoke(&S::do_something, s));	// same as s.do_something();
	}
}

namespace example_6
{
	struct MyClass
	{
		std::map<int, std::string> dict{ {1, "bark"}, {2, "roar"}, {3, "hiss"}};
	};
}