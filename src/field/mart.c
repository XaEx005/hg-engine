#include "../../include/debug.h"
#include "../../include/pokemon.h"
#include "../../include/save.h"
#include "../../include/script.h"
#include "../../include/types.h"
#include "../../include/constants/item.h"

#ifdef MART_EXPANSION

struct MartItem {
    u16 item_id;
    u16 override_cost;
};

struct BadgeMartItems {
    u16 item_id;
    u8 required_badges;
};

// note: limited to 203 items (~34 pages)
const struct BadgeMartItems sBadgeMart[] = {
    { ITEM_POKE_BALL,      0 },
    { ITEM_GREAT_BALL,     3 },
    { ITEM_ULTRA_BALL,     5 },
    { ITEM_POTION,         0 },
    { ITEM_SUPER_POTION,   1 },
    { ITEM_HYPER_POTION,   5 },
    { ITEM_MAX_POTION,     7 },
    { ITEM_FULL_RESTORE,   8 },
    { ITEM_RARE_CANDY,     0 },
    { ITEM_REVIVE,         3 },
    { ITEM_ANTIDOTE,       0 },
    { ITEM_PARALYZE_HEAL,  0 },
    { ITEM_AWAKENING,      1 },
    { ITEM_BURN_HEAL,      1 },
    { ITEM_ICE_HEAL,       1 },
    { ITEM_FULL_HEAL,      4 },
    { ITEM_ESCAPE_ROPE,    1 },
    { ITEM_REPEL,          1 },
    { ITEM_SUPER_REPEL,    2 },
    { ITEM_MAX_REPEL,      4 },
    { ITEM_SUN_STONE,      5 },
    { ITEM_MOON_STONE,     5 },
    { ITEM_FIRE_STONE,     5 },
    { ITEM_THUNDER_STONE,  5 },
    { ITEM_WATER_STONE,    5 },
    { ITEM_LEAF_STONE,     5 },
    { ITEM_ICE_STONE,      5 },
    { ITEM_LINKING_CORD,   5 },
    { ITEM_KINGS_ROCK,     5 },
    { ITEM_DUSK_STONE,     7 },
    { ITEM_SHINY_STONE,    7 },
};

void LONG_CALL InitMartUI(void *taskManager, FieldSystem *fieldSystem, const u16 *items, int kind, int buySell, int decoWhich, const struct MartItem *priceOverrides);

u16 sCherrygroveCityMart[] = {
    ITEM_HEAL_BALL, ITEM_NEST_BALL,
    0xFFFF
};

u16 sVioletCityMart[] = {
    ITEM_HEAL_BALL, ITEM_NEST_BALL, ITEM_QUICK_BALL, 
    0xFFFF
};

u16 sAzaleaCityMart[] = {
    ITEM_NEST_BALL, ITEM_QUICK_BALL, ITEM_NET_BALL,
    0xFFFF
};

u16 sGoldenrodDepartmentUpper2F[] = {
    ITEM_SUPER_POTION, ITEM_HYPER_POTION, ITEM_MAX_POTION, ITEM_REVIVE,
    ITEM_FULL_HEAL, ITEM_POKE_BALL, ITEM_GREAT_BALL, ITEM_ULTRA_BALL, ITEM_QUICK_BALL,
    ITEM_TIMER_BALL, ITEM_REPEAT_BALL, ITEM_LUXURY_BALL, ITEM_ESCAPE_ROPE, 
    ITEM_SUPER_REPEL, ITEM_MAX_REPEL, 0xFFFF
};

u16 sGoldenrodDepartmentLower2F[] = {
    ITEM_FULL_INCENSE, ITEM_LAX_INCENSE, ITEM_LUCK_INCENSE, ITEM_ODD_INCENSE, 
    ITEM_PURE_INCENSE, ITEM_ROCK_INCENSE, ITEM_ROSE_INCENSE, ITEM_SEA_INCENSE, 
    ITEM_WAVE_INCENSE, 0xFFFF
};

u16 sGoldenrodDepartment3F[] = {
    ITEM_ABILITY_CAPSULE, ITEM_EXP_SHARE, ITEM_BLACK_BELT, ITEM_EXPERT_BELT, ITEM_FOCUS_SASH, 
    0xFFFF
};

u16 sGoldenrodDepartment4F[] = {
    ITEM_PROTEIN, ITEM_IRON, ITEM_CALCIUM, ITEM_ZINC, ITEM_CARBOS,
    ITEM_HP_UP, ITEM_PP_UP, ITEM_POWER_WEIGHT, ITEM_POWER_BRACER, ITEM_POWER_BELT, 
    ITEM_POWER_LENS, ITEM_POWER_BAND, ITEM_POWER_ANKLET, ITEM_MACHO_BRACE,
    0xFFFF
};

u16 sGoldenrodDepartment5F[] = {
    ITEM_ORAN_BARRY, 0xFFFF
};

u16 sGoldenrodHerbs[] = { 
    ITEM_LONELY_MINT, ITEM_ADAMANT_MINT, ITEM_NAUGHTY_MINT, ITEM_BRAVE_MINT, 
    ITEM_BOLD_MINT, ITEM_IMPISH_MINT, ITEM_LAX_MINT, ITEM_RELAXED_MINT, 
    ITEM_MODEST_MINT, ITEM_MILD_MINT, ITEM_RASH_MINT, ITEM_QUIET_MINT, 
    ITEM_CALM_MINT, ITEM_GENTLE_MINT, ITEM_CAREFUL_MINT, ITEM_SASSY_MINT, 
    ITEM_TIMID_MINT, ITEM_HASTY_MINT, ITEM_JOLLY_MINT, ITEM_NAIVE_MINT, 
    ITEM_SERIOUS_MINT, 0xFFFF
};

u16 sEcruteakMart[] = {
    ITEM_NET_BALL, ITEM_DUSK_BALL, ITEM_QUICK_BALL,
    0xFFFF
};

u16 sOlivineMart[] = {
    ITEM_DIVE_BALL, ITEM_QUICK_BALL,
    0xFFFF
};

u16 sCianwoodPharmacy[] = {
    ITEM_HEAL_POWDER, ITEM_ENERGY_POWDER, ITEM_ENERGY_ROOT, ITEM_REVIVAL_HERB,
    0xFFFF
};

u16 sBlackthornAndBattleFrontierMart[] = {
    ITEM_NET_BALL, ITEM_DUSK_BALL, ITEM_HEAVY_BALL, ITEM_QUICK_BALL, ITEM_TIMER_BALL, ITEM_REPEAT_BALL,
    0xFFFF
};

u16 sIndigoPlateau[] = {
    ITEM_MAX_REPEL, ITEM_FULL_RESTORE, ITEM_MAX_REVIVE, 0xFFFF
};

u16 sVermilionAndSafariMart[] = {
    ITEM_ORAN_BARRY,
    0xFFFF
};

u16 sSaffronMart[] = {
    0xFFFF
};

u16 sLavenderMart[] = {
    0xFFFF
};

u16 sCeruleanMart[] = {
    0xFFFF
};

u16 sCeladonDepartmentUpper2F[] = {
    0xFFFF
};

u16 sCeladonDepartmentLower2F[] = {
    0xFFFF
};

u16 sCeladonDepartment3F[] = {
    0xFFFF
};

u16 sCeladonDepartment4F[] = {
    0xFFFF
};

u16 sCeladonDepartmentLeft5F[] = {
    0xFFFF
};

u16 sCeladonDepartmentRight5F[] = {
    0xFFFF
};

u16 sFuschiaMart[] = {
    0xFFFF
};

u16 sPewterMart[] = {
    0xFFFF
};

u16 sViridianMart[] = {
    0xFFFF
};

u16 sMtMoonSquare[] = {
    0xFFFF
};

u16 sMahoganyPreRocketHideout[] = {
    ITEM_TINY_MUSHROOM, 0xFFFF
};

u16 sMahoganyPostRocketHideout[] = {
    ITEM_METAL_COAT, ITEM_BLACK_AUGURITE, ITEM_RAZOR_CLAW, ITEM_RAZOR_FANG, 
    ITEM_PEAT_BLOCK, ITEM_PROTECTOR, ITEM_OVAL_STONE, ITEM_UP_GRADE, 
    ITEM_DUBIOUS_DISC, 0xFFFF
};

BOOL ScrCmd_MartBuy(SCRIPTCONTEXT *ctx) {
    u16 unused = ScriptGetVar(ctx);

    u16 items[NELEMS(sBadgeMart) + 1];
    u8 badgeCount = 0;
    u8 index = 0;

    for (int i = 0; i < 16; i++) {
        if (PlayerProfile_TestBadgeFlag(Sav2_PlayerData_GetProfileAddr(ctx->fsys->savedata), i) == TRUE) {
            badgeCount++;
        }
    }

    for (int i = 0; i < NELEMS(sBadgeMart); i++) {
        if (badgeCount >= sBadgeMart[i].required_badges) {
            items[index] = sBadgeMart[i].item_id;
            index++;
        }
    }

    items[index] = 0xFFFF;
    InitMartUI(ctx->taskman, ctx->fsys, items, 0, 0, 0, 0); // this doesn't honor price overrides
    return TRUE;
}

#endif // MART_EXPANSION

#ifdef POKEATHLON_SHOP_EXPANSION

const struct MartItem sPokeathlonShopSunday[] = {
    { ITEM_RED_APRICORN,   200  },
    { ITEM_BLUE_APRICORN,  200  },
    { ITEM_BLACK_APRICORN, 200  },
    { ITEM_MOOMOO_MILK,    100  },
    { ITEM_KINGS_ROCK,     3000 },
    { ITEM_HEART_SCALE,    1000 },
    { ITEM_FULL_RESTORE,   500  },
    { ITEM_NUGGET,         500  },
    { ITEM_SUN_STONE,      3000 },
    { ITEM_FIRE_STONE,     2500 },
    { ITEM_SHINY_STONE,    3000 },
    { ITEM_DAWN_STONE,     3000 },
    { 0xFFFF,              0    },
};

const struct MartItem sPokeathlonShopMonday[] = {
    { ITEM_RED_APRICORN,   200  },
    { ITEM_BLUE_APRICORN,  200  },
    { ITEM_GREEN_APRICORN, 200  },
    { ITEM_MOOMOO_MILK,    100  },
    { ITEM_MOON_STONE,     3000 },
    { ITEM_RARE_CANDY,     2000 },
    { ITEM_FULL_RESTORE,   500  },
    { ITEM_KINGS_ROCK,     3000 },
    { ITEM_SUN_STONE,      3000 },
    { ITEM_WATER_STONE,    2500 },
    { ITEM_SHINY_STONE,    3000 },
    { ITEM_DUSK_STONE,     3000 },
    { 0xFFFF,              0    },
};

const struct MartItem sPokeathlonShopTuesday[] = {
    { ITEM_YELLOW_APRICORN, 200  },
    { ITEM_PINK_APRICORN,   200  },
    { ITEM_WHITE_APRICORN,  200  },
    { ITEM_MOOMOO_MILK,     100  },
    { ITEM_FIRE_STONE,      2500 },
    { ITEM_PP_UP,           1000 },
    { ITEM_FULL_RESTORE,    500  },
    { ITEM_METAL_COAT,      2500 },
    { ITEM_WATER_STONE,     2500 },
    { ITEM_LEAF_STONE,      2500 },
    { ITEM_DUSK_STONE,      3000 },
    { ITEM_DAWN_STONE,      3000 },
    { 0xFFFF,               0    },
};

const struct MartItem sPokeathlonShopWednesday[] = {
    { ITEM_BLUE_APRICORN,  200  },
    { ITEM_PINK_APRICORN,  200  },
    { ITEM_BLACK_APRICORN, 200  },
    { ITEM_MOOMOO_MILK,    100  },
    { ITEM_WATER_STONE,    2500 },
    { ITEM_HEART_SCALE,    1000 },
    { ITEM_FULL_RESTORE,   500  },
    { ITEM_DRAGON_SCALE,   2500 },
    { ITEM_THUNDER_STONE,  2500 },
    { ITEM_MOON_STONE,     3000 },
    { ITEM_SHINY_STONE,    3000 },
    { ITEM_DAWN_STONE,     3000 },
    { 0xFFFF,              0    },
};

const struct MartItem sPokeathlonShopThursday[] = {
    { ITEM_YELLOW_APRICORN, 200  },
    { ITEM_PINK_APRICORN,   200  },
    { ITEM_WHITE_APRICORN,  200  },
    { ITEM_MOOMOO_MILK,     100  },
    { ITEM_THUNDER_STONE,   2500 },
    { ITEM_PP_UP,           1000 },
    { ITEM_FULL_RESTORE,    500  },
    { ITEM_KINGS_ROCK,      3000 },
    { ITEM_FIRE_STONE,      2500 },
    { ITEM_LEAF_STONE,      2500 },
    { ITEM_SHINY_STONE,     3000 },
    { ITEM_DUSK_STONE,      3000 },
    { 0xFFFF,               0    },
};

const struct MartItem sPokeathlonShopFriday[] = {
    { ITEM_RED_APRICORN,    200  },
    { ITEM_YELLOW_APRICORN, 200  },
    { ITEM_GREEN_APRICORN,  200  },
    { ITEM_MOOMOO_MILK,     100  },
    { ITEM_METAL_COAT,      2500 },
    { ITEM_NUGGET,          500  },
    { ITEM_FULL_RESTORE,    500  },
    { ITEM_DRAGON_SCALE,    2500 },
    { ITEM_WATER_STONE,     2500 },
    { ITEM_SUN_STONE,       3000 },
    { ITEM_DUSK_STONE,      3000 },
    { ITEM_DAWN_STONE,      3000 },
    { 0xFFFF,               0    },
};

const struct MartItem sPokeathlonShopSaturday[] = {
    { ITEM_GREEN_APRICORN,  200  },
    { ITEM_WHITE_APRICORN,  200  },
    { ITEM_BLACK_APRICORN,  200  },
    { ITEM_MOOMOO_MILK,     100  },
    { ITEM_LEAF_STONE,      2500 },
    { ITEM_RARE_CANDY,      2000 },
    { ITEM_FULL_RESTORE,    500  },
    { ITEM_METAL_COAT,      2500 },
    { ITEM_THUNDER_STONE,   2500 },
    { ITEM_SHINY_STONE,     3000 },
    { ITEM_DUSK_STONE,      3000 },
    { ITEM_DAWN_STONE,      3000 },
    { 0xFFFF,               0    },
};

#endif // POKEATHLON_SHOP_EXPANSION