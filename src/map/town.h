/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.org/
*/

#ifndef SRC_MAP_TOWN_H_
#define SRC_MAP_TOWN_H_

#include "game/movement/position.h"

class Town
{
	public:
		explicit Town(const std::string initTownName, uint8_t initTownId, const Position initPosition);

		const Position& getTemplePosition() const {
			return templePosition;
		}
		const std::string& getName() const {
			return name;
		}

		void setTemplePos(Position pos) {
			templePosition = pos;
		}
		void setName(std::string newName) {
			this->name = std::move(newName);
		}
		uint8_t getID() const {
			return id;
		}

	private:
		uint32_t id;
		std::string name;
		Position templePosition;
};

class Towns
{
	public:
		Towns() = default;
		~Towns() {
			for (const auto& it : townMap) {
				delete it.second;
			}
		}

		// non-copyable
		Towns(const Towns&) = delete;
		Towns& operator=(const Towns&) = delete;

		bool addTown(uint8_t townId, Town* town);

		Town* getTown(const std::string& townName) const;

		Town* getTown(uint8_t townId) const;

		const std::map<uint8_t, Town*>& getTowns() const;

	private:
		std::map<uint8_t, Town*> townMap;
};

#endif  // SRC_MAP_TOWN_H_
