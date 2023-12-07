#ifndef YTL_TYPES
#define YTL_TYPES

#include <variant>

namespace ytl
{

	///Generic error message carrier type
	struct base_error
	{
		virtual ~base_error() = default;

		virtual const char* get() const
		{
			return "unspecified error";
		}
	};

	///Type that takes an error string as constructor. Note that it is just a pointer.
	struct whatever : base_error
	{
		whatever(const char* message) : message(message) {}

		const char* get() const final
		{
			return message;
		}

	private:
		const char* const message;
	};

	///Rust style `Result` class
	template<class T, class Err>
	class result
	{
		std::variant<T, Err> content;

	public:
		result(T&& value) : content(value) {}
		result(Err&& error) : content(error){}

		bool is_ok() const
		{
			return std::holds_alternative<T>(content);
		}

		bool is_err() const
		{
			return std::holds_alternative<Err>(content);
		}

		T& ok()
		{
			return std::get<T>(content);
		}

		T ok() const
		{
			return std::get<T>(content);
		}

		const Err err() const
		{
			return std::get<Err>(content);
		}
	};
	
}

#endif