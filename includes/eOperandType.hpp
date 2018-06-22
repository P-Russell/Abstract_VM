#ifndef EOPERANDTYPE_HPP
#define EOPERANDTYPE_HPP

class eOperandType {
	public:
		enum _types
		{
			INT_8,
			INT_16,
			INT_32,
			FLOAT,
			DOUBLE
		};
		eOperandType(int type = DOUBLE): _type(type) {}
		~eOperandType(void) {}
		eOperandType(const eOperandType & rhs) : _type(rhs._type) {}
		eOperandType & operator = (const eOperandType & rhs);
		eOperandType & operator = (const int & rhs);
		int getType(void) const;
		void setType(int type);	
		bool operator==( eOperandType const & rhs );
		bool operator!=( eOperandType const & rhs ); 
		bool operator>( eOperandType const & rhs );
		bool operator<( eOperandType const & rhs );
		bool operator>=( eOperandType const & rhs ); 
		bool operator<=( eOperandType const & rhs );
	private:
		int _type;
};

#endif
