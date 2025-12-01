#include <DirectXMath.h>

static inline constexpr auto operator+ (const DirectX::XMFLOAT3& v1,
                                        const DirectX::XMFLOAT3& v2)
{
    return DirectX::XMFLOAT3
    { 
        v1.x + v2.x,
        v1.y + v2.y, 
        v1.z + v2.z
    };
}

static inline constexpr auto operator- (const DirectX::XMFLOAT3& v1,
                                        const DirectX::XMFLOAT3& v2)
{
    return DirectX::XMFLOAT3
    { 
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };
}

static inline constexpr auto operator* (const DirectX::XMFLOAT3& v1,
                                        const DirectX::XMFLOAT3& v2)
{
    return DirectX::XMFLOAT3
    {
        v1.x * v2.x,
        v1.y * v2.y,
        v1.z * v2.z
    };
}

static inline constexpr auto operator/ (const DirectX::XMFLOAT3& v1,
                                        const DirectX::XMFLOAT3& v2)
{
    return DirectX::XMFLOAT3
    {
        v1.x / v2.x,
        v1.y / v2.y,
        v1.z / v2.z
    };
}

static inline constexpr auto operator% (const DirectX::XMFLOAT3& v1,
                                        const DirectX::XMFLOAT3& v2)
{
    return DirectX::XMFLOAT3
    {
        ::fmodf(v1.x, v2.x),
        ::fmodf(v1.y, v2.y),
        ::fmodf(v1.z, v2.z)
    };
}
