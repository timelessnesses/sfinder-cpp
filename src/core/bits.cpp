#include "bits.hpp"

namespace core {
    Bitboard deleteLine_(Bitboard x, LineKey key) {
        switch (key) {
            case 3072:
                return (x & 1023L) | ((x >> 10) & 1073740800L) | ((x >> 20) & 1098437885952L);
            case 2048:
                return (x & 1099511627775L) | ((x >> 10) & 1124800395214848L);
            case 1024:
                return (x & 1023L) | ((x >> 10) & 1125899906841600L);
            case 0:
                return (x);
            case 3073:
                return ((x >> 20) & 1048575L) | ((x >> 30) & 1072693248L);
            case 2049:
                return ((x >> 10) & 1073741823L) | ((x >> 20) & 1098437885952L);
            case 1025:
                return ((x >> 20) & 1099511627775L);
            case 1:
                return ((x >> 10) & 1125899906842623L);
            case 3074:
                return (x & 1023L) | ((x >> 10) & 1047552L) | ((x >> 30) & 1072693248L);
            case 2050:
                return (x & 1073741823L) | ((x >> 20) & 1098437885952L);
            case 1026:
                return (x & 1023L) | ((x >> 10) & 1047552L) | ((x >> 20) & 1099510579200L);
            case 2:
                return (x & 1073741823L) | ((x >> 10) & 1125898833100800L);
            case 3075:
                return ((x >> 20) & 1023L) | ((x >> 40) & 1047552L);
            case 2051:
                return ((x >> 10) & 1048575L) | ((x >> 30) & 1072693248L);
            case 1027:
                return ((x >> 20) & 1023L) | ((x >> 30) & 1073740800L);
            case 3:
                return ((x >> 10) & 1048575L) | ((x >> 20) & 1099510579200L);
            case 1051648:
                return (x & 1023L) | ((x >> 20) & 1047552L) | ((x >> 30) & 1072693248L);
            case 1050624:
                return (x & 1048575L) | ((x >> 10) & 1072693248L) | ((x >> 20) & 1098437885952L);
            case 1049600:
                return (x & 1023L) | ((x >> 20) & 1099511626752L);
            case 1048576:
                return (x & 1048575L) | ((x >> 10) & 1125899905794048L);
            case 1051649:
                return ((x >> 30) & 1023L) | ((x >> 40) & 1047552L);
            case 1050625:
                return ((x >> 10) & 1023L) | ((x >> 20) & 1047552L) | ((x >> 30) & 1072693248L);
            case 1049601:
                return ((x >> 30) & 1073741823L);
            case 1048577:
                return ((x >> 10) & 1023L) | ((x >> 20) & 1099511626752L);
            case 1051650:
                return (x & 1023L) | ((x >> 40) & 1047552L);
            case 1050626:
                return (x & 1048575L) | ((x >> 30) & 1072693248L);
            case 1049602:
                return (x & 1023L) | ((x >> 30) & 1073740800L);
            case 1048578:
                return (x & 1048575L) | ((x >> 20) & 1099510579200L);
            case 1051651:
                return ((x >> 50) & 1023L);
            case 1050627:
                return ((x >> 10) & 1023L) | ((x >> 40) & 1047552L);
            case 1049603:
                return ((x >> 40) & 1048575L);
            case 1048579:
                return ((x >> 10) & 1023L) | ((x >> 30) & 1073740800L);
            case 2100224:
                return (x & 1023L) | ((x >> 10) & 1073740800L);
            case 2099200:
                return (x & 1099511627775L);
            case 2098176:
                return (x & 1023L) | ((x >> 10) & 1099511626752L);
            case 2097152:
                return (x & 1125899906842623L);
            case 2100225:
                return ((x >> 20) & 1048575L);
            case 2099201:
                return ((x >> 10) & 1073741823L);
            case 2098177:
                return ((x >> 20) & 1073741823L);
            case 2097153:
                return ((x >> 10) & 1099511627775L);
            case 2100226:
                return (x & 1023L) | ((x >> 10) & 1047552L);
            case 2099202:
                return (x & 1073741823L);
            case 2098178:
                return (x & 1023L) | ((x >> 10) & 1047552L) | ((x >> 20) & 1072693248L);
            case 2097154:
                return (x & 1073741823L) | ((x >> 10) & 1098437885952L);
            case 2100227:
                return ((x >> 20) & 1023L);
            case 2099203:
                return ((x >> 10) & 1048575L);
            case 2098179:
                return ((x >> 20) & 1023L) | ((x >> 30) & 1047552L);
            case 2097155:
                return ((x >> 10) & 1048575L) | ((x >> 20) & 1072693248L);
            case 3148800:
                return (x & 1023L) | ((x >> 20) & 1047552L);
            case 3147776:
                return (x & 1048575L) | ((x >> 10) & 1072693248L);
            case 3146752:
                return (x & 1023L) | ((x >> 20) & 1073740800L);
            case 3145728:
                return (x & 1048575L) | ((x >> 10) & 1099510579200L);
            case 3148801:
                return ((x >> 30) & 1023L);
            case 3147777:
                return ((x >> 10) & 1023L) | ((x >> 20) & 1047552L);
            case 3146753:
                return ((x >> 30) & 1048575L);
            case 3145729:
                return ((x >> 10) & 1023L) | ((x >> 20) & 1073740800L);
            case 3148802:
                return (x & 1023L);
            case 3147778:
                return (x & 1048575L);
            case 3146754:
                return (x & 1023L) | ((x >> 30) & 1047552L);
            case 3145730:
                return (x & 1048575L) | ((x >> 20) & 1072693248L);
            case 3148803:
                return (0L);
            case 3147779:
                return ((x >> 10) & 1023L);
            case 3146755:
                return ((x >> 40) & 1023L);
            case 3145731:
                return ((x >> 10) & 1023L) | ((x >> 30) & 1047552L);
            default:
                assert(false);
        }
    }

    Bitboard deleteLine(Bitboard x, LineKey mask) {
        // 1073741823 = (1 << 30) - 1
        auto key = ((mask >> 29) | (mask & 1073741823));
        return deleteLine_(x, key);
    }

    Bitboard insertBlackLine_(Bitboard x, LineKey key) {
        switch (key) {
            case 3072:
                return (x & 1023L) | ((x & 1073740800L) << 10) | ((x & 1098437885952L) << 20) | (1124800396262400L);
            case 2048:
                return (x & 1099511627775L) | ((x & 1124800395214848L) << 10) | (1124800395214848L);
            case 1024:
                return (x & 1023L) | ((x & 1125899906841600L) << 10) | (1047552L);
            case 0:
                return (x);
            case 3073:
                return ((x & 1048575L) << 20) | ((x & 1072693248L) << 30) | (1124800396263423L);
            case 2049:
                return ((x & 1073741823L) << 10) | ((x & 1098437885952L) << 20) | (1124800395215871L);
            case 1025:
                return ((x & 1099511627775L) << 20) | (1048575L);
            case 1:
                return ((x & 1125899906842623L) << 10) | (1023L);
            case 3074:
                return (x & 1023L) | ((x & 1047552L) << 10) | ((x & 1072693248L) << 30) | (1125898834148352L);
            case 2050:
                return (x & 1073741823L) | ((x & 1098437885952L) << 20) | (1125898833100800L);
            case 1026:
                return (x & 1023L) | ((x & 1047552L) << 10) | ((x & 1099510579200L) << 20) | (1098438933504L);
            case 2:
                return (x & 1073741823L) | ((x & 1125898833100800L) << 10) | (1098437885952L);
            case 3075:
                return ((x & 1023L) << 20) | ((x & 1047552L) << 40) | (1125898834149375L);
            case 2051:
                return ((x & 1048575L) << 10) | ((x & 1072693248L) << 30) | (1125898833101823L);
            case 1027:
                return ((x & 1023L) << 20) | ((x & 1073740800L) << 30) | (1098438934527L);
            case 3:
                return ((x & 1048575L) << 10) | ((x & 1099510579200L) << 20) | (1098437886975L);
            case 1051648:
                return (x & 1023L) | ((x & 1047552L) << 20) | ((x & 1072693248L) << 30) | (1124801468955648L);
            case 1050624:
                return (x & 1048575L) | ((x & 1072693248L) << 10) | ((x & 1098437885952L) << 20) | (1124801467908096L);
            case 1049600:
                return (x & 1023L) | ((x & 1099511626752L) << 20) | (1073740800L);
            case 1048576:
                return (x & 1048575L) | ((x & 1125899905794048L) << 10) | (1072693248L);
            case 1051649:
                return ((x & 1023L) << 30) | ((x & 1047552L) << 40) | (1124801468956671L);
            case 1050625:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 20) | ((x & 1072693248L) << 30) | (1124801467909119L);
            case 1049601:
                return ((x & 1073741823L) << 30) | (1073741823L);
            case 1048577:
                return ((x & 1023L) << 10) | ((x & 1099511626752L) << 20) | (1072694271L);
            case 1051650:
                return (x & 1023L) | ((x & 1047552L) << 40) | (1125899906841600L);
            case 1050626:
                return (x & 1048575L) | ((x & 1072693248L) << 30) | (1125899905794048L);
            case 1049602:
                return (x & 1023L) | ((x & 1073740800L) << 30) | (1099511626752L);
            case 1048578:
                return (x & 1048575L) | ((x & 1099510579200L) << 20) | (1099510579200L);
            case 1051651:
                return ((x & 1023L) << 50) | (1125899906842623L);
            case 1050627:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 40) | (1125899905795071L);
            case 1049603:
                return ((x & 1048575L) << 40) | (1099511627775L);
            case 1048579:
                return ((x & 1023L) << 10) | ((x & 1073740800L) << 30) | (1099510580223L);
            case 2100224:
                return (x & 1023L) | ((x & 1073740800L) << 10) | (1152920405096266752L);
            case 2099200:
                return (x & 1099511627775L) | (1152920405095219200L);
            case 2098176:
                return (x & 1023L) | ((x & 1099511626752L) << 10) | (1151795604701051904L);
            case 2097152:
                return (x & 1125899906842623L) | (1151795604700004352L);
            case 2100225:
                return ((x & 1048575L) << 20) | (1152920405096267775L);
            case 2099201:
                return ((x & 1073741823L) << 10) | (1152920405095220223L);
            case 2098177:
                return ((x & 1073741823L) << 20) | (1151795604701052927L);
            case 2097153:
                return ((x & 1099511627775L) << 10) | (1151795604700005375L);
            case 2100226:
                return (x & 1023L) | ((x & 1047552L) << 10) | (1152921503534152704L);
            case 2099202:
                return (x & 1073741823L) | (1152921503533105152L);
            case 2098178:
                return (x & 1023L) | ((x & 1047552L) << 10) | ((x & 1072693248L) << 20) | (1151796703138937856L);
            case 2097154:
                return (x & 1073741823L) | ((x & 1098437885952L) << 10) | (1151796703137890304L);
            case 2100227:
                return ((x & 1023L) << 20) | (1152921503534153727L);
            case 2099203:
                return ((x & 1048575L) << 10) | (1152921503533106175L);
            case 2098179:
                return ((x & 1023L) << 20) | ((x & 1047552L) << 30) | (1151796703138938879L);
            case 2097155:
                return ((x & 1048575L) << 10) | ((x & 1072693248L) << 20) | (1151796703137891327L);
            case 3148800:
                return (x & 1023L) | ((x & 1047552L) << 20) | (1152920406168960000L);
            case 3147776:
                return (x & 1048575L) | ((x & 1072693248L) << 10) | (1152920406167912448L);
            case 3146752:
                return (x & 1023L) | ((x & 1073740800L) << 20) | (1151795605773745152L);
            case 3145728:
                return (x & 1048575L) | ((x & 1099510579200L) << 10) | (1151795605772697600L);
            case 3148801:
                return ((x & 1023L) << 30) | (1152920406168961023L);
            case 3147777:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 20) | (1152920406167913471L);
            case 3146753:
                return ((x & 1048575L) << 30) | (1151795605773746175L);
            case 3145729:
                return ((x & 1023L) << 10) | ((x & 1073740800L) << 20) | (1151795605772698623L);
            case 3148802:
                return (x & 1023L) | (1152921504606845952L);
            case 3147778:
                return (x & 1048575L) | (1152921504605798400L);
            case 3146754:
                return (x & 1023L) | ((x & 1047552L) << 30) | (1151796704211631104L);
            case 3145730:
                return (x & 1048575L) | ((x & 1072693248L) << 20) | (1151796704210583552L);
            case 3148803:
                return (1152921504606846975L);
            case 3147779:
                return ((x & 1023L) << 10) | (1152921504605799423L);
            case 3146755:
                return ((x & 1023L) << 40) | (1151796704211632127L);
            case 3145731:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 30) | (1151796704210584575L);
            default:
                assert(false);
        }
    }

    Bitboard insertBlackLine(Bitboard x, LineKey mask) {
        // 1073741823 = (1 << 30) - 1
        auto key = ((mask >> 29) | (mask & 1073741823));
        return insertBlackLine_(x, key);
    }

    Bitboard insertWhiteLine_(Bitboard x, LineKey key) {
        switch (key) {
            case 3072:
                return (x & 1023L) | ((x & 1073740800L) << 10) | ((x & 1098437885952L) << 20);
            case 2048:
                return (x & 1099511627775L) | ((x & 1124800395214848L) << 10);
            case 1024:
                return (x & 1023L) | ((x & 1125899906841600L) << 10);
            case 0:
                return (x);
            case 3073:
                return ((x & 1048575L) << 20) | ((x & 1072693248L) << 30);
            case 2049:
                return ((x & 1073741823L) << 10) | ((x & 1098437885952L) << 20);
            case 1025:
                return ((x & 1099511627775L) << 20);
            case 1:
                return ((x & 1125899906842623L) << 10);
            case 3074:
                return (x & 1023L) | ((x & 1047552L) << 10) | ((x & 1072693248L) << 30);
            case 2050:
                return (x & 1073741823L) | ((x & 1098437885952L) << 20);
            case 1026:
                return (x & 1023L) | ((x & 1047552L) << 10) | ((x & 1099510579200L) << 20);
            case 2:
                return (x & 1073741823L) | ((x & 1125898833100800L) << 10);
            case 3075:
                return ((x & 1023L) << 20) | ((x & 1047552L) << 40);
            case 2051:
                return ((x & 1048575L) << 10) | ((x & 1072693248L) << 30);
            case 1027:
                return ((x & 1023L) << 20) | ((x & 1073740800L) << 30);
            case 3:
                return ((x & 1048575L) << 10) | ((x & 1099510579200L) << 20);
            case 1051648:
                return (x & 1023L) | ((x & 1047552L) << 20) | ((x & 1072693248L) << 30);
            case 1050624:
                return (x & 1048575L) | ((x & 1072693248L) << 10) | ((x & 1098437885952L) << 20);
            case 1049600:
                return (x & 1023L) | ((x & 1099511626752L) << 20);
            case 1048576:
                return (x & 1048575L) | ((x & 1125899905794048L) << 10);
            case 1051649:
                return ((x & 1023L) << 30) | ((x & 1047552L) << 40);
            case 1050625:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 20) | ((x & 1072693248L) << 30);
            case 1049601:
                return ((x & 1073741823L) << 30);
            case 1048577:
                return ((x & 1023L) << 10) | ((x & 1099511626752L) << 20);
            case 1051650:
                return (x & 1023L) | ((x & 1047552L) << 40);
            case 1050626:
                return (x & 1048575L) | ((x & 1072693248L) << 30);
            case 1049602:
                return (x & 1023L) | ((x & 1073740800L) << 30);
            case 1048578:
                return (x & 1048575L) | ((x & 1099510579200L) << 20);
            case 1051651:
                return ((x & 1023L) << 50);
            case 1050627:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 40);
            case 1049603:
                return ((x & 1048575L) << 40);
            case 1048579:
                return ((x & 1023L) << 10) | ((x & 1073740800L) << 30);
            case 2100224:
                return (x & 1023L) | ((x & 1073740800L) << 10);
            case 2099200:
                return (x & 1099511627775L);
            case 2098176:
                return (x & 1023L) | ((x & 1099511626752L) << 10);
            case 2097152:
                return (x & 1125899906842623L);
            case 2100225:
                return ((x & 1048575L) << 20);
            case 2099201:
                return ((x & 1073741823L) << 10);
            case 2098177:
                return ((x & 1073741823L) << 20);
            case 2097153:
                return ((x & 1099511627775L) << 10);
            case 2100226:
                return (x & 1023L) | ((x & 1047552L) << 10);
            case 2099202:
                return (x & 1073741823L);
            case 2098178:
                return (x & 1023L) | ((x & 1047552L) << 10) | ((x & 1072693248L) << 20);
            case 2097154:
                return (x & 1073741823L) | ((x & 1098437885952L) << 10);
            case 2100227:
                return ((x & 1023L) << 20);
            case 2099203:
                return ((x & 1048575L) << 10);
            case 2098179:
                return ((x & 1023L) << 20) | ((x & 1047552L) << 30);
            case 2097155:
                return ((x & 1048575L) << 10) | ((x & 1072693248L) << 20);
            case 3148800:
                return (x & 1023L) | ((x & 1047552L) << 20);
            case 3147776:
                return (x & 1048575L) | ((x & 1072693248L) << 10);
            case 3146752:
                return (x & 1023L) | ((x & 1073740800L) << 20);
            case 3145728:
                return (x & 1048575L) | ((x & 1099510579200L) << 10);
            case 3148801:
                return ((x & 1023L) << 30);
            case 3147777:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 20);
            case 3146753:
                return ((x & 1048575L) << 30);
            case 3145729:
                return ((x & 1023L) << 10) | ((x & 1073740800L) << 20);
            case 3148802:
                return (x & 1023L);
            case 3147778:
                return (x & 1048575L);
            case 3146754:
                return (x & 1023L) | ((x & 1047552L) << 30);
            case 3145730:
                return (x & 1048575L) | ((x & 1072693248L) << 20);
            case 3148803:
                return (0L);
            case 3147779:
                return ((x & 1023L) << 10);
            case 3146755:
                return ((x & 1023L) << 40);
            case 3145731:
                return ((x & 1023L) << 10) | ((x & 1047552L) << 30);
            default:
                assert(false);
        }
    }

    Bitboard insertWhiteLine(Bitboard x, LineKey mask) {
        // 1073741823 = (1 << 30) - 1
        int key = (int) ((mask >> 29) | (mask & 1073741823));
        return insertWhiteLine_(x, key);
    }

    int bitCount(uint64_t b) {
        b -= (b >> 1) & 0x5555555555555555ULL;
        b = ((b >> 2) & 0x3333333333333333ULL) + (b & 0x3333333333333333ULL);
        b = ((b >> 4) + b) & 0x0F0F0F0F0F0F0F0FULL;
        return (b * 0x0101010101010101ULL) >> 56;
    }
}
