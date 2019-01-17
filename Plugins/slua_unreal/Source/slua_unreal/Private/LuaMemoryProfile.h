// Tencent is pleased to support the open source community by making sluaunreal available.

// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the BSD 3-Clause License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at

// https://opensource.org/licenses/BSD-3-Clause

// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#pragma once
#include "CoreMinimal.h"
#include "lua/lua.hpp"

namespace slua {

#if WITH_EDITOR
	struct LuaMemInfo {
		FString hint;
		size_t size;
		void* ptr;

		int push(lua_State* L) const;
	};

	typedef TMap<void*, LuaMemInfo> MemoryDetail;
#endif

    class LuaMemoryProfile {
    public:
        static void* alloc (void *ud, void *ptr, size_t osize, size_t nsize);
		static size_t total();
		static void start();
		static void stop();
#if WITH_EDITOR
		static const MemoryDetail& memDetail();
    private:

        static void addRecord(class LuaState* LS,void* ptr,size_t size);
        static void removeRecord(class LuaState* LS,void* ptr,size_t size);
#endif
    };

}