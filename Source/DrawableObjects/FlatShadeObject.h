#ifndef AIR_WEAVER_DRAWABLEOBJECTS_FLATSHADEROBJECT_H_
#define AIR_WEAVER_DRAWABLEOBJECTS_FLATSHADEROBJECT_H_

#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/Math/Color.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/Shaders/FlatGL.h>
#include <Magnum/GL/Mesh.h>

using namespace Corrade;
using namespace Magnum;
using Object3D = SceneGraph::Object<SceneGraph::MatrixTransformation3D>;

/****************************************************************************************************/
class FlatShadeObject : public SceneGraph::Drawable3D {
public:
    explicit FlatShadeObject(Object3D& object, Shaders::FlatGL3D& shader,
                             const Color3& color, GL::Mesh& mesh,
                             SceneGraph::DrawableGroup3D* const drawables) :
        SceneGraph::Drawable3D{object, drawables}, m_Shader(shader), m_Color(color), m_Mesh(mesh) {}

    virtual void draw(const Matrix4& transformation, SceneGraph::Camera3D& camera) override {
        if(m_bEnable) {
            m_Shader.setColor(m_Color)
                .setTransformationProjectionMatrix(camera.projectionMatrix() * transformation)
                .draw(m_Mesh);
        }
    }

    FlatShadeObject& setColor(const Color3& color) { m_Color = color; return *this; }
    FlatShadeObject& setEnable(bool bStatus) { m_bEnable = bStatus; return *this; }

    Color3& color() { return m_Color; }
    const Color3& color() const { return m_Color; }
    bool& enabled() { return m_bEnable; }
    const bool& enabled() const { return m_bEnable; }

private:
    bool             m_bEnable { true };
    Shaders::FlatGL3D& m_Shader;
    Color3           m_Color;
    GL::Mesh&        m_Mesh;
};

#endif // AIR_WEAVER_DRAWABLEOBJECTS_FLATSHADEROBJECT_H_
