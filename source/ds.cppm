export module stk.ds;

import std.core;

using namespace std;

namespace NStk::NDs
{
	export 
	template<class T, size_t N>
	class TFixedVector
	{
	public:
		TFixedVector<T, N>()
			: m_uCount(0)
		{
		}

		bool Append(T const& koValue)
		{
			if (m_uCount < N)
			{
				m_aArr[m_uCount++] = koValue;
				return true;
			}

			return false;
		}

		bool RemoveAtOrdered(size_t i)
		{
			if (i < m_uCount)
			{
				for (size_t j = i; j < m_uCount - 1; ++j)
				{
					m_aArr[j] = m_aArr[j + 1];
				}

				--m_uCount;
				return true;
			}

			return false;
		}

		bool RemoveAtUnordered(size_t i)
		{
			if (i < m_uCount)
			{
				m_aArr[i] = m_aArr[--m_uCount];
				return true;
			}

			return false;
		}

		T const& operator[](size_t i) const
		{
			return m_aArr[i];
		}

		T& operator[](size_t i)
		{
			return m_aArr[i];
		}

		size_t Count() const
		{
			return m_uCount;
		}

	private:
		array<T, N> m_aArr;
		size_t m_uCount;
	};
}