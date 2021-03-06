#pragma once

#include <cstdint>
#include <limits>

namespace openloco
{
    using company_id_t = uint8_t;

    namespace company_id
    {
        constexpr company_id_t neutral = 15;
        constexpr company_id_t null = std::numeric_limits<company_id_t>::max();
    }

#pragma pack(push, 1)
    struct company
    {
        uint16_t var_00;
        uint8_t pad_02[0x08 - 0x02];
        uint32_t var_08;
        uint8_t pad_0C[0x50 - 0x0C];
        uint16_t available_vehicles; // 0x50
        uint8_t pad_52[0x8BB0 - 0x52];
        uint8_t var_8BB0[9];
        uint8_t pad_8BB9[0x8FA8 - 0x8BB9];

        company_id_t id() const;
        bool empty() const;
        void ai_think();
    };
#pragma pack(pop)

    bool is_player_company(company_id_t id);
}
