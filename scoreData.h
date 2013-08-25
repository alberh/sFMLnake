/*
    sFMLnake: A simple Snake clone made with SFML 2.
    Copyright (C) 2013  Alberto Garc�a Gonz�lez

    This file is part of sFMLnake.

    sFMLnake is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sFMLnake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with sFMLnake.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCOREDATA_H
#define SCOREDATA_H

#include <vector>

class ScoreData {
public:
    ScoreData();
    const std::vector<unsigned int>& getHighScore() const;
    void save();
    void addScore(unsigned int points);
private:
    std::vector<unsigned int> score;
};

inline const std::vector<unsigned int>& ScoreData::getHighScore() const {
    return score;
}

#endif
