#ifndef __BLOCKWORLD_MESSAGEOBSERVER_H__
#define __BLOCKWORLD_MESSAGEOBSERVER_H__

namespace BlockWorld {
	class ConnectResponseMessage;
	class JoinMessage;
	class LeaveMessage;
	class LoadMapMessage;
	class StartGameMessage;
	class SpawnMessage;
	class UpdateMessage;
	class ShotMessage;
	class DeathMessage;
	class MessageObserver {
		protected:
			MessageObserver()  { }
			virtual ~MessageObserver() { }
		
		public:
			virtual void onConnectResponse(ConnectResponseMessage& message) { }
			virtual void onJoin(JoinMessage& message) { }
			virtual void onLeave(LeaveMessage& message) { }
			virtual void onLoadMap(LoadMapMessage& message) { }
			virtual void onStartGame(StartGameMessage& message) { }
			virtual void onSpawn(SpawnMessage& message) { }
			virtual void onUpdate(UpdateMessage& message) { }
			virtual void onShot(ShotMessage& message) { }
			virtual void onDeath(DeathMessage& message) { }
	};
};

#endif
