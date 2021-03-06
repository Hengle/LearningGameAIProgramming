/**
 * Copyright (c) 2013 David Young dayoung@goliathdesigns.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *  claim that you wrote the original software. If you use this software
 *  in a product, an acknowledgment in the product documentation would be
 *  appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *  misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source
 *  distribution.
 */

#include "PrecompiledHeaders.h"

#include "demo_framework/include/LuaFile.h"
#include "demo_framework/include/LuaFileSerializer.h"

LuaFileSerializer::LuaFileSerializer() {
}

LuaFileSerializer::~LuaFileSerializer() {
}

void LuaFileSerializer::ImportLuaFile(
    Ogre::DataStreamPtr& stream, LuaFile* const luaFile) {
    size_t dataSize = stream->size();

    if (dataSize)
    {
        char* const data = new char[dataSize + 1];

        stream->read(data, dataSize);
        luaFile->SetData(data, dataSize);

        data[dataSize] = 0;
    }
}