#include "socket.hpp"
#include <gtest/gtest.h>

using namespace net;

TEST(socket, constructor)
{
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv4, Type::TCP));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv4, Type::UDP));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv6, Type::TCP));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv6, Type::UDP));
	EXPECT_NO_THROW(Socket mySocket(Domain::UNIX, Type::TCP));
	EXPECT_NO_THROW(Socket mySocket(Domain::UNIX, Type::UDP));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv4, Type::TCP, 6));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv6, Type::TCP, 6));

	EXPECT_NO_THROW(Socket mySocket(Domain::IPv4, Type::SEQPACKET, 132));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv6, Type::SEQPACKET, 132));
	EXPECT_NO_THROW(Socket s(Domain::UNIX, Type::SEQPACKET));

	EXPECT_ANY_THROW(Socket mySocket(Domain::IPv4, Type::TCP, 41));
	EXPECT_ANY_THROW(Socket mySocket(Domain::IPv4, Type::UDP, 6));
	EXPECT_ANY_THROW(Socket mySocket(Domain::UNIX, Type::TCP, 3));


	EXPECT_NO_THROW(Socket s(Domain::UNIX, Type::SEQPACKET, 0));
}


TEST(Socket, ConstructorRaw)
{
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv4, Type::RAW, 4));
	EXPECT_NO_THROW(Socket mySocket(Domain::IPv6, Type::RAW, 4));
}
