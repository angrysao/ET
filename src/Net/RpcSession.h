#ifndef NET_RPC_SESSION_H
#define NET_RPC_SESSION_H

#include <list>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace Hainan {

class RpcSession: private boost::noncopyable,
		public boost::enable_shared_from_this<RpcSession>
{
private:
	typedef boost::unordered_set<RpcSessionPtr> RpcSessionSet;

	boost::asio::ip::tcp::socket socket;
	std::list<RpcResponsePtr> responses;
	RpcSessionSet& sessions;
	ThreadPool& thread_pool;

public:
	RpcSession(RpcSessionSet& rpc_sessions, ThreadPool& pool);
	~RpcSession();
	boost::asio::ip::tcp::socket& Socket();
	void Start();
	void Stop();
};

typedef boost::shared_ptr<RpcSession> RpcSessionPtr;

}

#endif // NET_RPC_SESSION_H
