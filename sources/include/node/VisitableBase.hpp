#ifndef NODE_VISITABLE_BASE_HPP
#define NODE_VISITABLE_BASE_HPP

#include <rapidxml/rapidxml.hpp>

#include <memory>
#include <node/Type.hpp>
namespace Node
{
    namespace XML
    {
        struct Document;
        struct Element;
        struct Data;
        struct CDATA;
        struct Comment;
        struct Declaration;
        struct Doctype;
        struct ProcessingIntruction;

        struct Visitor
        {
            virtual void visit(const Document  & node) = 0;
            virtual void visit(const Element  & node) = 0;
            virtual void visit(const Data  & node) = 0;
            virtual void visit(const CDATA  & node) = 0;
            virtual void visit(const Declaration  & node) = 0;
            virtual void visit(const Comment  & node) = 0;
            virtual void visit(const Doctype  & node) = 0;
            virtual void visit(const ProcessingIntruction  & node) = 0;

            virtual ~Visitor() = default;
        };

#define UNUSED(a) if(sizeof(&a) == sizeof(&a)){}
        struct VisitorHelper
            : public Visitor
        {
            VisitorHelper()
                : Visitor{}
            {}
            virtual void visit(const Document  & node) override
            {
                UNUSED(node);
            }

            virtual void visit(const CDATA  & node) override
            {
                UNUSED(node);
            }

            virtual void visit(const Declaration  & node) override
            {
                UNUSED(node);
            }

            virtual void visit(const Comment  & node) override
            {
                UNUSED(node);
            }

            virtual void visit(const Doctype  & node) override
            {
                UNUSED(node);
            }

            virtual void visit(const ProcessingIntruction  & node) override
            {
                UNUSED(node);
            }
            virtual ~VisitorHelper() = default;
        };
#undef UNUSED

        // the common base to allow dynamic dispatch
        struct VisitableBase
        {
            virtual void accept(Visitor & v) const = 0;
            virtual ~VisitableBase() = default;
        };

        struct Document : VisitableBase
        {
            DocumentNode m_node;

            Document(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}

            virtual void accept(Visitor & v) const override
            {
                v.visit(*this);
            }
        };

        struct Data : VisitableBase
        {
            DataNode m_node;
            Data(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}


            virtual void accept(Visitor & v) const override
            {
                v.visit(*this);
            }
        };

        struct CDATA : VisitableBase
        {
            CDATA_Node m_node;

            CDATA(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}

            virtual void accept(Visitor & v) const
            {
                v.visit(*this);
            }

        };

        struct Comment : VisitableBase
        {
            CommentNode m_node;

            Comment(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}

            virtual void accept(Visitor & v) const
            {
                v.visit(*this);
            }

        };

        struct Declaration : VisitableBase
        {
            DeclarationNode m_node;

            Declaration(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}

            virtual void accept(Visitor & v) const
            {
                v.visit(*this);
            }

        };

        struct Doctype : VisitableBase
        {
            DoctypeNode m_node;

            Doctype(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}

            virtual void accept(Visitor & v) const
            {
                v.visit(*this);
            }

        };

        struct ProcessingIntruction : VisitableBase
        {
            ProcessingIntructionNode m_node;

            ProcessingIntruction(rapidxml::xml_node<> * node=nullptr)
                : m_node{node}
            {}

            virtual void accept(Visitor & v) const
            {
                v.visit(*this);
            }
        };

        struct NopVisitor
            : public VisitorHelper
        {
            bool m_print_next_value;

            NopVisitor();
            virtual void visit(const Element & node) override;
            virtual void visit(const Data  & node) override;
            virtual ~NopVisitor() = default;
        };
    } // Node::XML
} // Node

#endif /*  ndef NODE_VISITABLE_BASE_HPP */
