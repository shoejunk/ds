import stk.ds;
import stk.log;

using namespace stk;

int main()
{
	c_fixed_vector<int, 10> vec;
	vec.append(5);
	vec.append(6);
	vec.append(7);
	vec.emplace(3);

	debugln("Initial:");
	for (auto& i : vec)
	{
		debugln("{}", i);
	}

	vec.remove_at_ordered(0);

	debugln("remove_at_ordered(0):");
	for (auto& i : vec)
	{
		debugln("{}", i);
	}

	vec.append(8);
	vec.remove_at_unordered(0);
	debugln("append(8); remove_at_unordered(0):");
	for (auto& i : vec)
	{
		debugln("{}", i);
	}

	return 0;
}
