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

		class iterator {
		public:
			using iterator_category = std::forward_iterator_tag;
			using value_type = T;
			using difference_type = std::ptrdiff_t;
			using pointer = T*;
			using reference = T&;

			iterator(T* ptr) : ptr(ptr) {}

			reference operator*() { return *ptr; }
			pointer operator->() { return ptr; }

			iterator& operator++()
			{
				++ptr;
				return *this;
			}

			iterator operator++(int)
			{
				iterator tmp = *this;
				++ptr;
				return tmp;
			}

			bool operator==(const iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const iterator& other) const { return ptr != other.ptr; }

		private:
			T* ptr;
		};

		class const_iterator
		{
		public:
			using iterator_category = std::forward_iterator_tag;
			using value_type = T;
			using difference_type = std::ptrdiff_t;
			using pointer = const T*;
			using reference = const T&;

			const_iterator(const T* ptr) : ptr(ptr) {}

			reference operator*() { return *ptr; }
			pointer operator->() { return ptr; }

			const_iterator& operator++()
			{
				++ptr;
				return *this;
			}

			const_iterator operator++(int)
			{
				const_iterator tmp = *this;
				++ptr;
				return tmp;
			}

			bool operator==(const const_iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }

		private:
			const T* ptr;
		};

		iterator begin() { return iterator(&m_aArr[0]); }
		iterator end() { return iterator(&m_aArr[m_uCount]); }

		const_iterator begin() const { return const_iterator(&m_aArr[0]); }
		const_iterator end() const { return const_iterator(&m_aArr[m_uCount]); }
		const_iterator cbegin() const { return const_iterator(&m_aArr[0]); }
		const_iterator cend() const { return const_iterator(&m_aArr[m_uCount]); }

	private:
		array<T, N> m_aArr;
		size_t m_uCount;
	};
}