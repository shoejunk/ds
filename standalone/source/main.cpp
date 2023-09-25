import stk.ds;
import stk.log;

using namespace stk::ds;
using namespace NStk::NLog;

int main()
{
	fixed_vector<int, 10> vec;
	vec.append(5);
	vec.append(6);
	vec.append(7);

	Log("Initial:\n");
	for (auto& i : vec)
	{
		Log("%d\n", i);
	}

	vec.remove_at_ordered(0);

	Log("remove_at_ordered(0):\n");
	for (auto& i : vec)
	{
		Log("%d\n", i);
	}

	vec.append(8);
	vec.remove_at_unordered(0);
	Log("append(8); remove_at_unordered(0):\n");
	for (auto& i : vec)
	{
		Log("%d\n", i);
	}

	return 0;
}
