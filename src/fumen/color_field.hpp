#ifndef FUMEN_CPP_COLORFIELD_HPP
#define FUMEN_CPP_COLORFIELD_HPP

#include <array>
#include <vector>

#include "../core/types.hpp"
#include "../core/factory.hpp"

namespace fumen {
    enum ColorType {
        Empty = 0,
        I = 1,
        L = 2,
        O = 3,
        Z = 4,
        T = 5,
        J = 6,
        S = 7,
        Gray = 8,
    };

    class ColorConverter {
    public:
        static ColorConverter create() noexcept;

        ColorConverter(
                const std::array<ColorType, 7> pieceToColor,
                const std::array<core::PieceType, 9> colorToPiece
        ) : pieceToColor_(pieceToColor), colorToPiece_(colorToPiece) {};

        ColorType parseToColorType(core::PieceType piece) const;

        core::PieceType parseToPieceType(ColorType color) const;

    private:
        const std::array<ColorType, 7> pieceToColor_;
        const std::array<core::PieceType, 9> colorToPiece_;
    };

    const auto kDefaultConverter = ColorConverter::create();

    class ColorField {
    public:
        explicit ColorField(const int height) noexcept : height(height) {
            int size = height * 10;
            field.reserve(size);
            for (int i = 0; i < size; ++i) {
                field.emplace_back(ColorType::Empty);
            }
        };

        void setBlock(ColorType colorType, int x, int y);

        int at(int x, int y) const;

        bool existsAt(int x, int y) const;

        void put(const core::Blocks &blocks, int x, int y);

        void clearLine();

    private:
        int height;
        std::vector<int> field{};
    };
}

#endif //FUMEN_CPP_COLORFIELD_HPP