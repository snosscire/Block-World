#ifndef __BLOCKWORLD_MESSAGEOBSERVER_H__
#define __BLOCKWORLD_MESSAGEOBSERVER_H__

namespace BlockWorld {
	class ConnectResponseMessage;
	class JoinMessage;
	class LeaveMessage;
	class UpdateMessage;
	
	class MessageObserver {
		protected:
			MessageObserver()  { }
			virtual ~MessageObserver() { }
		
		public:
			virtual void onConnectResponse(ConnectResponseMessage& message) { }
			virtual void onJoin(JoinMessage& message) { }
			virtual void onLeave(LeaveMessage& message) { }
			virtual void onUpdate(UpdateMessage& message) { }
	};
};

#endif
