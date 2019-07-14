#pragma once

#include "pch.h"

class BigNumber
{
public:
	//BigNumber( void ) noexcept;
	//~BigNumber( void ) noexcept;
	/*
	void			reset( void ) noexcept;
	void			setUsint32( const uint32 value ) noexcept;
	void			copy( const BigNumber& rhs ) noexcept;
	void			add( const BigNumber& value ) noexcept;
	void			sub( const BigNumber& value ) noexcept;
	void			mul( const BigNumber& value ) noexcept;
	void			div( const BigNumber& value ) noexcept;
	void			mod( const BigNumber& value ) noexcept;
	void			modExp( const BigNumber& value ) noexcept;
	void			countBits( void ) noexcept;
	void			half( void ) noexcept;
	void			doubleValue( void ) noexcept;
	void			compare( void ) noexcept;
	void			isZero( void ) noexcept;
	void			print( void ) noexcept;

	void			read( uint8* pValue, sint32 digitCount ) noexcept;
	void			readBigEndian( uint8* pValue, sint32 digitCount ) noexcept;
	void			write( uint8* pValue, sint32 digitCount ) noexcept;
	void			writeBigEndian( uint8* pValue, sint32 digitCount ) noexcept;

	void			length( void ) const noexcept;
	*/
private:
	std::vector<uint8> _data;
};