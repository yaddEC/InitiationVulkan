#include "VertexBuffer.h"

VkVertexInputBindingDescription Vertex::getBindingDescription()
{
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
}

std::array<VkVertexInputAttributeDescription, 3> Vertex::getAttributeDescriptions()
{
    std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};

    attributeDescriptions[0].binding = 0;
    attributeDescriptions[0].location = 0;
    attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
    attributeDescriptions[0].offset = offsetof(Vertex, pos);

    attributeDescriptions[1].binding = 0;
    attributeDescriptions[1].location = 1;
    attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
    attributeDescriptions[1].offset = offsetof(Vertex, color);

    attributeDescriptions[2].binding = 0;
    attributeDescriptions[2].location = 2;
    attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
    attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

    return attributeDescriptions;
}

bool QueueFamilyIndices::isComplete()
{
        return graphicsFamily.has_value() && presentFamily.has_value();
    
}

size_t VertexHasher::operator()(const Vertex& vertex) const
{
    {
        size_t posHash = std::hash<glm::vec3>()(vertex.pos);
        size_t texCoordHash = std::hash<glm::vec2>()(vertex.texCoord);
        return posHash ^ (texCoordHash << 1);
    }
}

bool VertexEqual::operator()(const Vertex& v1, const Vertex& v2) const
{
    {
        return v1.pos == v2.pos && v1.texCoord == v2.texCoord;
    }
}
