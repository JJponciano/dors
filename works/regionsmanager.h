/**
 * @file regionsmanager.h
 * @brief file use for managed regions class
 * @copyright 2015 Jean-Jacques PONCIANO, Claire PRUDHOMME
 * All rights reserved.
 * This file is part of scn reader.
 *
 * scn reader is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * scn reader is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>
 * @author Jean-Jacques PONCIANO and Claire PRUDHOMME
 * Contact: ponciano.jeanjacques@gmail.com
 * @version 0.1
 */
#ifndef REGIONSMANAGER_H
#define REGIONSMANAGER_H

#include "region.h"
class RegionsManager
{
public:
    RegionsManager();
    /**
     * @brief RegionsManager
     * @param minsize minimum size of a region for detect a merge
     * @param neighborsDistance distance between neighbors
     * @param maxSize maximum number of points that a region may contain
     */
    RegionsManager(int minsize, float neighborsDistance, int maxSize);
    ~RegionsManager();
    /**
     * @brief addPoint add a point into a correct region
     * @param point to be added
     * @return true the addition did not require a merger
     */
    bool addPoint(PointGL point);
    /**
     * @brief getRegion return a region
     * @param ID identifier of the region to be returned
     * @return return the region having indentifier ID
     */
    Region getRegion(int ID);
    /**
     * @brief remove remove a region
     * @param ID identifier of the region to be removed
     */
    void remove(int ID);
    /**
     * @brief removeRegions it removes regions and it tests if a region is not too small for die
     * @param RegionsID identifier of the regions to be removed
     * @return true if no region was too small
     * @warning Maybe this work is not quite accurate
     */
    bool removeRegions(QVector<int> RegionsID);
    /**
     * @brief split split a region in two regions
     * @param regionID identifier of the region to be splited
     * @return true if a region was too small
     */
    bool split(int regionID);
    /**
     * @brief intoRegions test  if the point belongs to the region
     * @param pt point to be tested.
     * @return identifiers of each region containing the point
     */
    QVector<int> intoRegions(PointGL point) const;
    /**
     * @brief checkRegion check all region
     * @param widthmax max width of the region
     * @return true if all region have a width less than widthmax
     */
    bool checkRegion(float widthmax);
    void clear();
    QVector<Region> getRegions() const;
    void setRegions(const QVector<Region> &value);

private:
    int generatingID();
    QVector<Region>regions;
    int nbregions;
    int maxSize;
int minSize;
float neighborsDistance;
void addInNewRegion(PointGL point);
void add(int ID, PointGL point);
};

#endif // REGIONSMANAGER_H
